// we are given an array of number nums and an Integer target
// we have to return if we can choose any subset of nums whose sum is equal to target

public class CombinationSum1 {
    public static boolean solve(int target, int[] nums) {
        boolean[][] dp = new boolean[nums.length + 1][target + 1];
        // dp[i][j] represents , is it possible to select subset from nums till index i
        // to make sum equal to j;
        // first row represents the empty subset;
        // we can make sum equal to 0 with empty subset;
        for (int i = 0; i < nums.length; i++)
            dp[i][0] = true;

        for (int i = 1; i <= nums.length; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]]; // consideing both inclusive and exclusive
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nums.length][target];

    }

    public static void main(String[] args) {
        int[] nums = { 4, 2, 7, 1, 3 };
        int target = 10;
        boolean ans = solve(target, nums);
        System.out.println(ans);

    }
}