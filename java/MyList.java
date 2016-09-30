/* Hernan Palombo */

/*
 * Example. Demonstrates how to use generic types and implement 
 * the Comparable interface 
 */

import java.io.*;
import java.util.Comparator;

class MyList<T extends Comparable<T>> {
  class Node {
    public T e;
    public Node n;
  }
  public Node f, l;

  void insert(T x) {
    Node n1 = new Node();
    n1.e = x;

    // empty list
    if(f==null) {
      f = l = n1;
      return;
    }

    Node p = f;
    if(p.e.compareTo(x) >= 0) { // insert at front
        n1.n = f;
        f = n1;
    } else {
      while(p.n != null && p.n.e.compareTo(x) < 0) p=p.n;
      n1.n = p.n;
      p.n = n1;
      if (n1.n == null) l = n1;
    }
  }

  void print() {
    Node p = f;
    int i=0;
    while(p != null) {
      System.out.println(i++ + ": " + p.e);
      p=p.n;
    }
  }

  public static void main(String[] args) {
    int x, y;
    x = y = 5;
    System.out.println("Hello " + (x+y));
    MyList<Integer> l = new MyList<Integer>();
    l.insert(5);
    l.insert(7);
    l.insert(9);
    l.insert(8);
    l.insert(4);
    l.print();
  }
}

