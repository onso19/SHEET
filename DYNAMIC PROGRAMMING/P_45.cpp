class Solution {
public:
    int max_=INT_MIN;
    map<int,map<int,long int>> dp;
    int solve(int temp,vector<int>& nums,int i)
    {
        if(i==nums.size()-1)
        {
            return max(max_,temp*nums[i]);
        }
        if(dp[temp][i]!=0)return dp[temp][i];
        int res1=solve(temp*nums[i],nums,i+1);
        int res2=solve(1,nums,i+1);
        max_=max(max(temp*nums[i],res1),max(max_,res2));
        return dp[temp][i]=max_;
    }
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return solve(1,nums,0);
    }
};
