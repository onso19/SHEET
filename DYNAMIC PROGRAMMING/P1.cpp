class Solution{
public:
 int climbStairsHelper(int n, vector<int>& t){
        if(n<=1) return 1;
        if(t[n] != -1) return t[n];
        else return t[n] = climbStairsHelper(n-1, t) + climbStairsHelper(n-2, t);
    }
    int climbStairs(int n) {
        if(n<=1) return 1;
        vector<int> t(n+1,-1);
        return climbStairsHelper(n,t);
    }
};
