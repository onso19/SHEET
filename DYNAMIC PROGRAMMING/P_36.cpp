class Solution {
public:
vector<vector<int>>palin;
int minchanges(string &s,int si,int ei){
    if(palin[si][ei]!=-1){
        return palin[si][ei];
    }
    int i=si,j=ei;
    int count=0;
    while(i<j){
        if(s[i++]!=s[j--]){
            count++;
        }
    }
    return palin[si][ei]=count;
}
vector<vector<int>>dp;
int solve(string &s,int ind,int k){
    if(dp[ind][k]!=-1){
        return dp[ind][k];
    }
    if(ind==s.length()){
        return 1e9;
    }
    if(k==0){
        return minchanges(s,ind,s.length()-1);
    }
    int ans=1e9;
    for(int i=ind;i<s.length();i++){
        int changes=minchanges(s,ind,i);
        ans=min(ans,changes+solve(s,i+1,k-1));
    }
    return dp[ind][k]=ans;
}
int palindromePartition(string s, int k) {
    palin.resize(s.length(),vector<int>(s.length(),-1));
    dp.resize(s.length()+1,vector<int>(k,-1));
    return solve(s,0,k-1);
}
};
