package Practice;
import java.util.Scanner;

class reverseNo{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        int ans = 0;
        while(n != 0){
            int digit = n % 10;
            ans = ans*10 + digit;
            n /= 10;
        }
        System.out.println("Answer -> " + ans);

        s.close();
    }
}