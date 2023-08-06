public class BoundedKnapSack {
    public static int Solve(int W, int N, int[] val, int[] wt) {
        int[][] dp = new int[N + 1][W + 1];
        // dp[i][j] represents max value achieved with sack of capacity j and i-1 items;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= W; j++) {
                if (wt[i - 1] <= j) {
                    dp[i][j] = Math.max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }

            }
        }

        return dp[N][W];

    }

    public static void main(String[] args) {
        int W = 4; // capacity of sack
        int N = 3; // No of items
        int[] val = { 1, 2, 3 }; // values of items;
        int[] wt = { 3, 5, 1 }; // weights of items

        int ans = Solve(W, N, val, wt);
        System.out.println(ans);
    }
}