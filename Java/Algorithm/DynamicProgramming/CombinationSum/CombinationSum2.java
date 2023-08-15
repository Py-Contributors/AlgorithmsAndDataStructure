//In this problem repetition of numbers are allowed

public class CombinationSum2 {
    public static boolean solve(int[] nums, int target) {
        boolean[] dp = new boolean[target + 1];
        dp[0] = true; // we can make sum equal to 0 with an empty subset
        for (int i = 1; i < dp.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] <= i) {
                    dp[i] |= dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }

    public static void main(String[] args) {
        int[] nums = { 4, 2, 7, 9, 3 };
        int target = 10;
        boolean ans = solve(nums, target);
        System.out.println(ans);
    }

}
