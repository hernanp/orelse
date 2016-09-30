/* Hernan Palombo */
/* Playing with the collatz conjecture to demo fork */

#include <stdlib.h>
#include <stdio.h>

void collatz(int n, int child);

pid_t pid1;
pid_t pid2;

int main(int argc, char **argv) {
    if(argc != 2 || atoi(argv[1]) < 1 || atoi(argv[1]) > 34) {
        printf("usage: %s NUM\n", argv[0]);
        printf("  (where 0 < NUM < 35)\n");
        exit(1);
    }

    pid1=fork();

    if(pid1<0) { //error
        fprintf(stderr,"fork failed\n");
        return 1;
    } else if (pid1==0) { //child
        collatz(atoi(argv[1]),1);
    } else {
        pid2=fork();
        if(pid2<0) { //error
            fprintf(stderr,"fork failed\n");
            return 1;
        } else if(pid2==0) { //child
            collatz(atoi(argv[1])+3,2);
        } else { //parent
            wait(NULL);
            printf("One done!\n");
            wait(NULL);
            printf("Children Complete\n");
        }
    }
    exit(0);
}

void collatz(int n, int child){
    printf("From Child %d n=%d, ", child, n);
    while(n!=1){
        if(n%2==0) n=n/2;
        else n=n*3+1;
        printf("From Child %d n=%d, ", child, n);
    }
    printf("\n");
}

