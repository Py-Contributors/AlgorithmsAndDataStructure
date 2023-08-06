//this is similar to KnapSack but Here we can repeat the items
//this problem is quite similar to coinChange2

public class UnboundedKS {
    public static int solve(int W, int N, int[] val, int[] wt) {
        int[] dp = new int[W + 1];
        // dp[i] represents max Value achieved with sack of capacity of i
        for (int i = 0; i <= W; i++) {
            for (int j = 0; j < N; j++) {
                if (wt[j] <= i) {
                    dp[i] = Math.max(dp[i], val[j] + dp[i - wt[j]]);
                }
            }

        }

        return dp[W];
    }

    public static void main(String[] args) {
        int W = 4; // capacity of sack
        int N = 3; // No of items
        int[] val = { 1, 2, 3 }; // values of items;
        int[] wt = { 3, 5, 1 }; // weights of items
        int ans = solve(W, N, val, wt);
        System.out.println(ans);
    }
}
