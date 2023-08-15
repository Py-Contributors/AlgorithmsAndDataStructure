//This problem is very similar to HouseRobber1
//But in this problem house are arranged in circular manner
//that means 0th house is adjacent to n-1th house
public class HouseRobber2 {
    public static int getMaxLoot(int n, int[] loot) {
        // we will use two dp arrays inorder to solve this problem
        // suppose we have 10 houses 1 to 10
        // if we steal from house 1 then we cannot steal from house 10 , and for houses
        // 2 to 9 will be same as HouseRobber1
        // if we leave house1 then we can steal from house 10 and for houses 2 to 9 will
        // be same as HouseRobber1
        int[] dp1 = new int[n + 1];
        int[] dp2 = new int[n + 1];

        // stealing from house1
        dp1[0] = 0;
        dp1[1] = loot[0];
        // leaving the first hosue
        dp2[2] = 0;
        dp2[2] = 0;
        for (int i = 2; i <= n; i++) {
            dp1[i] = Math.max(dp1[i - 1], dp1[i - 2] + loot[i - 1]);
            dp2[i] = Math.max(dp2[i - 1], dp2[i - 2] + loot[i - 1]);
        }

        return Math.max(dp1[n - 1], dp2[n]);
    }

    public static void main(String[] args) {
        int n = 5; /// no of houses
        int[] loot = { 2, 7, 9, 3, 1 }; // loots in the houses
        int ans = getMaxLoot(n, loot);
        System.out.println(ans);
    }
}
