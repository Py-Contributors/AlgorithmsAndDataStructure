//in ClimbStairs3 we have to find minimum no of jumps required to reach nth level

import java.util.*;

public class ClimbStairs3 {
    public static int getNoOfWays(int n, int[] jumps) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        // dp[i] represents no of ways to reach nth step from ith steps
        // we know that no of jumps required to reach nth step from itself is 0
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= jumps[i] && i + j < dp.length; j++) {
                // find the least number of jumps requried to reach nth step
                dp[i] = Math.min(dp[i], dp[i + j]);
            }
            if (dp[i] != Integer.MAX_VALUE)
                dp[i]++; // taking a jump from ith step
        }
        return dp[0];
    }

    public static void main(String[] args) {
        int n = 6; // number of steps;
        int[] jumps = { 2, 3, 0, 1, 2, 3 };
        int ans = getNoOfWays(n, jumps);
        if (ans == Integer.MAX_VALUE) {
            System.out.println("Cannot Reach");
        } else
            System.out.println(ans);

    }

}
