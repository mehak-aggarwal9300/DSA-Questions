// https://leetcode.com/problems/two-sum/ 

class TwoSum {

    public static int[] twoSum(int[] nums, int target) {
        int dp[][] = new int[nums.length][nums.length];
        for(int i =0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                dp[i][j]=nums[i]+nums[j];
                if(dp[i][j] == target) return new int[] {i,j};
            }
        }
      return new int[] {-1,-1};  
    } 
    
}