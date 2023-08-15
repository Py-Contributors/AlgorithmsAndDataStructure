// We are a Professional Robber and we have to rob maximum loot from n houses
// along a street
// But we cannnot steal from two adjacent houses otherwise we would get caught
// we are given loot array where loot[i] represents ith house contains loot[i] money

public class HouseRobber1 {
    public static int getMaxLoot(int n, int[] loot) {
        int[] dp = new int[n + 1];
        // dp represents dp[i] represents max loot we can achieve till ith house;
        dp[0] = 0; // loot from 0 houses is 0
        dp[1] = loot[0]; // loot from 1st house
        for (int i = 2; i <= n; i++) {
            // we can either loot previous house or current house
            // we are maximizing out loot at every house
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + loot[i - 1]);

        }
        return dp[n];
    }

    public static void main(String[] args) {
        int n = 5; /// no of houses
        int[] loot = { 2, 7, 9, 3, 1 }; // loots in the houses
        int ans = getMaxLoot(n, loot);
        System.out.println(ans);

    }
}