class Solution {
public:
    string longestPalindrome(string s) {
        int memo[1001][1001];
        memset(memo, -1, sizeof(memo));
        vector<int> answer = {0, 0, 1};
        helper(0, s.size() - 1, s, memo, answer);
        return s.substr(answer[0], answer[2]);
    }
    
    bool helper(int l, int r, string &s, int memo[][1001], vector<int> &answer) {
		// Check if [ L ... R ] is already calculated before
        if (memo[l][r] != -1) {
            return memo[l][r];         
        }
        
		// Base case, every single letter or empty string is also a palindrome
        if (l >= r) {
            return true;
        }
        
        // Possible palindrome beginning
        bool found = false;
        if (s[l] == s[r]) {
            found = true && helper(l + 1, r - 1, s, memo, answer);
        }
        
        // Try other possibilities
        helper(l + 1, r , s, memo, answer);
        helper(l, r - 1, s, memo, answer);
        
        // Update longest palindrome position and width
        if (found && (r - l + 1) > answer[2]) {
            answer = {l, r, (r - l + 1)};
        }
        
        // Memoization
        memo[l][r] = found;
        
        return found;
    }
};



// also it can b solved using lcs 
// aditya verma
if(a[i-1]==b[j-1]){
t[i][j]=1+lps(i-1,j-1);
else t[i][j]=0;  
}
