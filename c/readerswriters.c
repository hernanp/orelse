/* Hernan Palombo */
/* Readers/Writers problem example */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <assert.h>
#include <signal.h>

#define MAX_READERS 10

sem_t mutex;
sem_t want;
sem_t read;

int shared;
int in_cs=0;
int reader_in_cs[MAX_READERS];
int rin=0;
int running=1;

void int_handler(int signal) {
  running = 0;
}

void error() {
  int i;
  printf("error:\n");
  printf("  in_cs = %d\n", in_cs);
  for(i=0; i<MAX_READERS; i++)
    printf("  reader_in_cs[%d] = %d\n", i, reader_in_cs[i]);
  running=0;
}

void relaxandspendtime() {
  int i;
  for(i = 0; i < 250000000; i++) i=i;
}

void * reader_thread(void *arg) {
  int read_count;
  int thread_num = *(int *)arg;

while(running) {
  sem_wait(&want);
  sem_getvalue(&read,&read_count);
  if(read_count==0) sem_wait(&mutex);
  sem_wait(&read);
  sem_post(&want);

  /* READ */
  reader_in_cs[thread_num]=1;
//  if(in_cs!=0) error();
  assert(in_cs==0);
  shared++;
  relaxandspendtime();
//  printf("in reader thread # %d, shared = %d\n", thread_num, shared);
//  if(in_cs!=0) error();
  assert(in_cs==0);
  reader_in_cs[thread_num]=0;
  /* end READ */

  sem_getvalue(&read, &read_count);
  if(read_count==1) sem_post(&mutex);
  sem_post(&read);
}

  return(NULL);
}

void * writer_thread(void *arg) {
while(running) {
//  printf("in writer thread\n");
  sem_wait(&want);
  sem_wait(&mutex);
  /* WRITE */
  in_cs=1;
  shared=0;
//  printf("writing\n");
//  fflush(stdout);
  in_cs=0;
  /* end WRITE */
  sem_post(&want);
  sem_post(&mutex);
}  

  return(NULL);
}

int main(int argc, char *argv[]) {
  int i;
  int nreaders;
  int tnum[MAX_READERS];

  signal(SIGINT, int_handler);

  if(argc != 2) {
    fprintf(stderr, "Invalid number of arguments.\n");
    fprintf(stderr, "Usage: %s NREADERS\n", argv[0]);
    exit(1);
  } else {
    nreaders=atoi(argv[1]);
    if(nreaders<1 || nreaders>10) {
      fprintf(stderr, "Invalid number of readers (must be between [1,10]).\n");
      exit(1);
    }
    printf("Running simulation...\n");
    printf("  (press CTRL+C to terminate)\n");
  }

  for(i=0;i<nreaders;i++) tnum[i]=i;

  /* declare thread ids */
  pthread_t tid[nreaders];
  pthread_t tid_writer;

  pthread_attr_t attr;

  /* init semaphores */
  if(sem_init(&mutex,0,1) || sem_init(&want,0,1) || sem_init(&read,0,MAX_READERS)) {
    perror("sem_init");
    exit(1);
  }

  /* Required to schedule thread independently. (Otherwise use NULL in place of attr) */
  pthread_attr_init(&attr);
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM); /* sys wide contention */
  /**/

  /* create the threads */
  for(i=0; i<(nreaders/2); i++)
    pthread_create(&tid[i], &attr, reader_thread, (void *) &tnum[i]);
  pthread_create(&tid_writer, &attr, writer_thread, NULL);
  for(i=(nreaders/2);i<nreaders; i++)
    pthread_create(&tid[i], &attr, reader_thread, (void *) &tnum[i]);

  /* wait for threads to finish */
  for(i=0; i<nreaders; i++) {
    pthread_join(tid[i], NULL);
  }
  pthread_join(tid_writer, NULL);

  /* destroy threads */
  if(sem_destroy(&mutex) || sem_destroy(&want) || sem_destroy(&read)) {
    perror("sem_destroy");
    exit(1);
  }
  
//  printf("all threads terminated.\n");

  exit(0);
}


