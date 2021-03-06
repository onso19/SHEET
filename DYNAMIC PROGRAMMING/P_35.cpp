class Solution {
public:
    int dp[2001][2001];
    int dp2[2001][2001];
    bool ispalindrome(string &str,int i,int j){
        if (i >= j) return 1;
        if (dp2[i][j] != -1) return dp2[i][j];
        if (str[i] == str[j]) return dp2[i][j] = ispalindrome(str, i + 1, j - 1);
        return dp2[i][j] = 0;
    }
    
    int solve(string &str, int i, int j){
        if(i>=j) return 0;
        if(ispalindrome(str,i,j)) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        dp[i][j] = INT_MAX;
        for(int k=i;k<j;k++){
            if(ispalindrome(str,i,k)){
               dp[i][j]=min(dp[i][j], solve(str,k+1,j)+1); 
            }                
        }
        return dp[i][j];
    }
    
    int minCut(string str) {
        int n = str.size();
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        return solve(str,0,n-1);
    }
};
