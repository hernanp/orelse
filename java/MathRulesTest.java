/* Hernan Palombo */
/* easy example */

import java.io.*;

public class MathRulesTest {

   public static void main (String[] args) {
       testRule1();
   }

    public static void testRule1() {
        int i;
        for (i = 2;;i+=2) {
            if ( (i*i) % 4 != 0) {
                break;
            } else {
                System.out.print(i + ".");
            }
        }
        System.out.println("\nFound it!");

    }

}
