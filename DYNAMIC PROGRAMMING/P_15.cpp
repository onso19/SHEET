class Solution {
public:
      int dp[601][10001];
     int solve(vector<int> &coins,int n,int amt)
    {
        if(n==0)
            return 0;
        if(amt<=0)
            return dp[n][amt]=1;   
        if(dp[n][amt]!=-1)
        {
            return dp[n][amt];
        }
        if(coins[n-1]<=amt)
        {
            //You have two choices: 
            //1: Either you take this coin and subtract its value from amt; Count of coins will inc by 1.
            //2: Don't take this coin.
            return dp[n][amt]=solve(coins,n,amt-coins[n-1])+solve(coins,n-1,amt);
        }
        else
        {
            //You can't take this coin as its value is greater than amt you have in hand.
            return dp[n][amt]=solve(coins,n-1,amt);
        }
    }
    int change(int amount, vector<int>& coins) {
     
            memset(dp,-1,sizeof(dp));
            int ans=solve(coins,coins.size(),amount);
        
            if(ans==0)
                return 0;
            else
                return ans;   
    }
};
