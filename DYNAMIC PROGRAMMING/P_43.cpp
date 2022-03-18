/*consider every subarray and return the one that has maximum sum is using recursive approach. Here we can state the approach as -

At each index i, we can either pick that element or not pick it.
If we pick current element, then all future element must also be picked since our array needs to be contiguous.
If we had picked any elements till now, we can either end further recursion at any time by returning sum formed till now or we can choose current element and recurse further. This denotes two choices of either choosing the subarray formed from 1st picked element till now or expanding the subarray by choosing current element respectively.
In the code below, we will use mustPick to denote whether we must compulsorily pick current element. When mustPick is true, we must either return 0 or pick current element and recurse further. If pickCur is false, we have both choices of not picking current element and moving on to next element, or picking the current one.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        vector<vector<int>> dp(2, vector<int>(size(nums), -1));
        return solve(nums, 0, false, dp);
    }
    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
        if(i >= size(A)) return mustPick ? 0 : -1e5;
        if(dp[mustPick][i] != -1) return dp[mustPick][i];
        if(mustPick)
            return dp[mustPick][i] = max(0, A[i] + solve(A, i+1, true, dp));  // either stop here or choose current element and recurse
        return dp[mustPick][i] = max(solve(A, i+1, false, dp), A[i] + solve(A, i+1, true, dp));// try both choosing current element or not choosing
    }
};
