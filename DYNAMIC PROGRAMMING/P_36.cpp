/*class Solution {
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
*/
class Solution {
public:
    int check(string &s, int start, int end)
    {
        if(end<start)
        {
            return 99999;
        }
        // cout<<start<<" "<<end;
        int ans=0;
        while(start<end)
        {
            if(s[start]!=s[end])
            {
                ans++;
            }
            start++;
            end--;
        }
        // cout<<" "<<ans<<endl;
        return ans;
    }
    int helper(string &s, int k , int start, int end, int ***arr)
    {
        // cout<<start<<" "<<end<<" "<<k<<" "<<endl;
        if(end<start)
        {
            if(k<=0)
            {
                // cout<<start<<" "<<end<<" "<<k<<" "<<0<<endl;
                return 0;
            }
            else
            {
                // cout<<start<<" "<<end<<" "<<k<<" "<<99999<<endl;
                return 99999; 
            }
        }
        
        if(end-start+1 == k)
        {
            arr[start][end][k]=0;
            // cout<<start<<" "<<end<<" "<<k<<" "<<0<<endl;
            return 0;
        }
        if(end-start+1<k)
        {
            // cout<<start<<" "<<end<<" "<<k<<" "<<99999<<endl;
            return 99999;
        }
        if(k==1)
        {
            int a= check(s,start,end);
            arr[start][end][k]=a;
            return a;
        }
        if(arr[start][end][k]!=-1)
        {
            // cout<<start<<" "<<end<<" "<<k<<" "<<arr[start][end][k]<<endl;
            return arr[start][end][k];
        }
        int ans=99999;
        for(int i=start;i<=end;i++)
        {
            int a=helper(s,1,start,i,arr);
            int b=helper(s,k-1,i+1,end,arr);
            ans=min(ans,a+b);
            
        }
        arr[start][end][k]=ans;
        // cout<<start<<" "<<end<<" "<<k<<" "<<ans<<endl;
        return ans;
        
        
    }
    int palindromePartition(string s, int k) {
        
        int ***arr=new int**[s.size()];
        for(int i=0;i<s.size();i++)
        {
            arr[i]=new int*[s.size()];
            for(int j=0;j<s.size();j++)
            {
                arr[i][j]=new int[k+1];     
                for(int m=0;m<=k;m++)
                {
                    arr[i][j][m]=-1;
                }
            }
        }
        
        return helper(s,k,0,s.size()-1,arr);
        
    }
};
