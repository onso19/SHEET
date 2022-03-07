class Solution {
public:
    int robHelper(vector<int>&nums, int i, vector<int> &dp){
        int n = nums.size();
        if(i>=n){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int a = robHelper(nums, i+2,dp) + nums[i];
        int b = robHelper(nums, i+1,dp);
        int ans = max(a,b);
        dp[i] = ans;
        return ans;
    }
    int rob(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+1);
        for(int i=0; i<=n; i++){
            dp[i] = -1;
        }
        return robHelper(nums,0,dp);
    }
};
