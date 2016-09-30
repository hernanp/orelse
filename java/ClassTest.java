/* Hernan Palombo */
/* class example */

public class ClassTest {
    public static void main(String[] args) {
        Test t = new Test();
        t.print();
    }
    public void print() {
        System.out.println("Happy " + this.getClass().getName() + "'s Day!");
    }
}
