/* Hernan Palombo */

/*
 * Example. Hashmap of a fixed size that does not deal with collissions. 
 * Demonstrates the use of generic types, hashing, and iterators.
 */

import java.util.*;

class MyHashMap<K,V> {
  K[] keys;
  V[] values;

  MyHashMap(int size) {
    keys = (K[]) new Object[size];
    values = (V[]) new Object[size];
  }

  V get(K key) {
    return (V) values[hash(key)];
  }

  V put(K key, V val) {
    int h = hash(key);
    V tmp = values[h];
    keys[h] = key;
    values[h] = val;
    return tmp;
  }

  int hash(K o) {
    return o.hashCode() % keys.length;
  }

  void print() {
    int i=0;
    while(i<keys.length) {
      System.out.println(i++ + ": " + keys[i-1] + ", " + values[i-1]);
    }
  }

  void printKeys() {
    Iterator<K> it = Arrays.asList(keys).iterator();
    int i=0;
    while(it.hasNext()) System.out.println(i++ + ": " + it.next());
  }

  public static void main(String[] args) {
    MyHashMap m = new MyHashMap(4);
    m.put(2, "You");
    m.put(4, "Hernan");
    m.print();
    m.printKeys();
    String s = new String("Hello");
    System.out.println(s.substring(0,1));
  }
}

