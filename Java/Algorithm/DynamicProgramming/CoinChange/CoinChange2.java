//In this problem we have to find out no of ways we can make up amount equals to the target

public class CoinChange2 {
    public static int getWays(int[] coins, int target) {
        int[] dp = new int[target + 1]; // dp[i] represents number of ways to make up amount equals to i
        // no of ways to make up amount equals to 0 is 1
        dp[0] = 1;
        for (int i = 0; i < coins.length; i++) {
            for (int j = coins[i]; j < dp.length; j++) {
                dp[j] += dp[j - coins[i]];

            }
        }
        return dp[target];
    }

    public static void main(String[] args) {
        int[] coins = { 1, 2, 5 };
        int target = 7;
        int ans = getWays(coins, target);
        System.out.println(ans);
    }
}
