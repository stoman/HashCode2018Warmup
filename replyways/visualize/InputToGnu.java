import java.io.FileNotFoundException;
import java.util.Scanner;

public class InputToGnu {
    public static void main(String[] args) throws FileNotFoundException {
        
        Scanner sc = new Scanner(System.in);
        
        int startx = sc.nextInt();
        int starty = sc.nextInt();
        // end
        sc.nextInt();
        sc.nextInt();
        
        int obs = sc.nextInt();
        
        for (int i = 0; i < obs; i++) {
            
            int a1 = sc.nextInt();
            int a2 = sc.nextInt();
            
            System.out.print(a1 + " " + a2 + "\n");
            System.out.print(sc.nextInt() + " " + sc.nextInt() + "\n");
            System.out.print(sc.nextInt() + " " + sc.nextInt() + "\n");
            System.out.print(a1 + " " + a2 + "\n");
            System.out.println();
        }
        
    }
}
