//this problem is very similar to climbStairs1
//But in this problem instead of 1 or 2 steps we can Take variable steps
//we given an array jumps where jump[i] represents from ith step we can go to i+jumps[i] ith steps;
//we have to start from 0th step and reach the nth step using jumps

import java.util.Scanner;

public class ClimbStairs2 {
    public static int getNoOfWays(int n, int[] jumps) {
        int[] dp = new int[n + 1];
        // dp[i] represents no of ways to reach nth step from ith steps
        // we assume we can reach nth step in one way from nth step itself
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= jumps[i] && i + j < dp.length; j++) {
                dp[i] += dp[i + j];
            }
        }
        return dp[0];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 6; // number of steps;
        int[] jumps = { 2, 3, 0, 1, 2, 3 };
        int ans = getNoOfWays(n, jumps);
        System.out.println(ans);

    }

}
