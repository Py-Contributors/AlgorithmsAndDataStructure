import java.util.Scanner;

public class ClimbStairs1 {

    public static int solution(int n) {
        int[] dp = new int[n + 1];
        // in dp array dp[i] represents no of ways to reach ith stair
        // we assume to reach 0th steps we need 1 steps
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                // handling edge case
                dp[i] = dp[i - 1];
                continue;
            }
            // we can reach the ith step from (i-2)th step by taking 2steps or from (i-1)th
            // step by taking 1 step
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = solution(n);
        System.out.println(ans);
        // sc.close();

    }

}
