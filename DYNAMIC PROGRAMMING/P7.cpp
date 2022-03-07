int helper{
   int i, w;
     
            if (i == 0 || w == 0)
               return dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                return dp[i][w] = max(val[i - 1] +
                                helper(i - 1,w - wt[i - 1]),
                                helper(i - 1,w));
            else
               return dp[i][w] =helper(i - 1,w);
        }
    }
    return dp[n][W];
}
int knapSack(int W, int wt[], int val[], int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(W + 1));
 return helper(W,wt,val,dp);
   
}
