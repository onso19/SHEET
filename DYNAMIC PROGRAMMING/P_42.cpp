class Solution{
    public:

 int getLongestChain(vector<vector<int>>& pairs,vector<vector<int>>&memo, int prevIndex, int index){        
        if(index > pairs.size())return 0;
     
        if(prevIndex!= 0 && memo[prevIndex][index] != -1){
            return memo[prevIndex][index];
        }
        
        int len1=0, len2=0, len3=0;
        // current apair not overlapping with previous pair
        
        if(prevIndex ==0 || pairs[prevIndex-1][1] < pairs[index-1][0]){
            len1 = getLongestChain(pairs, memo, index, index+1) + 1;// include pair
            len2 = getLongestChain(pairs, memo, prevIndex, index+1);// skip pair
        }else{
            len3 = getLongestChain(pairs, memo, prevIndex, index+1);
        }
        
        memo[prevIndex][index] = max(len1, max(len2, len3));
        
        return memo[prevIndex][index];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs));
        
        int n = pairs.size();
        int prev = 0;
        vector<vector<int>> memo(n+1, vector<int>(n+1,-1));
        
        for(int i=0; i<n+1; ++i){
            memo[i][0] = 0;
            memo[0][i] = 0;
        }
        
        int res = getLongestChain(pairs,memo, prev, 1);
        return res;
    }
};
