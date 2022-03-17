class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,0);
        int ans=0;
        ans = recur(s,0,dp);
        return ans;
    }
    int recur(string s, int pos, vector<int>& dp){
        if(pos==s.size())return 1;
        if(s[pos]=='0')return 0;
        if(pos==s.size()-1)return 1;
        if(dp[pos]>0)return dp[pos];
        string b = s.substr(pos,2);
        
        int way1 = recur(s,pos+1,dp);
        int way2=0;
        if(stoi(b)<=26&&stoi(b)>0){
            way2 = recur(s,pos+2,dp);
        }
        dp[pos]= way1+way2;
        return dp[pos];
    }
};
