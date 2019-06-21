import java.util.*;
import java.math.BigInteger;

public class b {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int len = Integer.parseInt(scan.nextLine());
        String str = scan.nextLine();
        int li = h;
        int ri = h+1;
        while(str.charAt(li) == '0') li--;
        if(li > 0){
            BigInteger sum = getsum(str, li, len);
            if(ans.compareTo(sum) > 0) {
                ans = sum;
            }
        }
        while(ri < len && str.charAt(ri) == '0') ri++;
        if(ri < len) {
            BigInteger sum = getsum(str, ri, len);
            if(ans.compareTo(sum) > 0) {
                ans = sum;
            }
        }
        System.out.println(ans);
    }
    public static BigInteger getsum(String str, int i, int len) {
        String left = str.substring(0, i);
        String right = str.substring(i, len);
        BigInteger leftInt = new BigInteger(left);
        BigInteger rightInt = new BigInteger(right);
        return leftInt.add(rightInt);
    }
}
