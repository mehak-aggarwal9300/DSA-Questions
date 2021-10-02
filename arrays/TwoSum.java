import java.util.Arrays; 

class TwoSum {
    public static void main(String[] args) {
        int nums[]={2,7,11,5};
        int target=9;
        int result[]=twoSum(nums,target);
        System.out.println(Arrays.toString(result));
    }

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