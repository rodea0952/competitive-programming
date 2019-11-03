import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String ans = "";
        for(int i=0; i<s.length(); i++){
            if('0' <= s.charAt(i) && s.charAt(i) <= '9') ans += s.charAt(i);
        }

        System.out.println(ans);
    }
}
