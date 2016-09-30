/* Hernan Palombo */
/* thread example */

import java.io.*;

class ThreadTest1 {
  static class MyThread implements Runnable {
    public void run() {
      System.out.println("Hello from thread");
    }
  }
  
  public static void main(String[] args) {
    MyThread mt = new MyThread();
    Thread t = new Thread(mt);
    t.start();

    int i=0;
    System.out.println(i = true ? 5:1);
  }
}

