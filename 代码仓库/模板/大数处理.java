import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        for (int caseNo = 0; caseNo < T; caseNo ++) {
            BigInteger a = new BigInteger(s.next(), 2);
            BigInteger b = new BigInteger(s.next(), 2);
            BigInteger c = a.gcd(b);
            System.out.println("Case #" + (caseNo + 1) + ": " + c.toString(2));
        }
    }
}
