//this is dynamic programming approach for coin change problem
//we  are given an array coins and int target
// we have tp return minimum number of coins which can make up target equal to target
public class CoinChange1 {
    public static int getMinCoins(int[] coins, int target) {
        int[] dp = new int[target + 1];
        // dp[i] represents minimum number of coins required to make up target = i;

        for (int i = 1; i < dp.length; i++) {
            int min = Integer.MAX_VALUE;
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] > i) // if coin's value is more than required target then we ignore it
                    continue;
                min = Math.min(min, dp[i - coins[j]]); // finding minimum number of coins to make up amount = i
            }
            if (min == Integer.MAX_VALUE || min == 100000) // if we cannnot make amount = i then we mark it as invalid
                dp[i] = 100000;
            else
                dp[i] = min + 1; // else we add one coin to the min no of coins needed
        }

        return dp[target] == 100000 ? -1 : dp[target];
    }

    public static void main(String[] args) {
        int[] coins = { 1, 2, 5 };
        int target = 11;
        int ans = getMinCoins(coins, target);
        System.out.println(ans);
    }
}
