// P 38 can be solve using P_37
class Solution {
    bool isPalin(int i, int j, string &s)
    {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<vector<int>>> memo;
    
    bool isPartitionPossible(int start, int end, string &s, int total) {
        if(start > end or total > 3) return false; 
        
        // no need to check for more then 3 palindromes strings
        
        if(end >= s.size())
        {
            if(isPalin(start, end, s) and total == 3) return true;
            return false;
        }
        
        if(memo[start][end][total] != -1) return memo[start][end][total];
        
        bool ans = false;
        if(isPalin(start, end, s)) 
        {
        // if substring from start to end index is palindromic then
        // increment total which is keeping track how many palindromes found
        // and also start from the next index to create more substrings
            ans |= isPartitionPossible(end + 1, end + 1, s, total + 1);
        }
        
        // if not palindromic start take more characters
        ans |= isPartitionPossible(start, end + 1, s, total);
        return memo[start][end][total] = ans;
        
    }
public:
    bool checkPartitioning(string s) {
        int n = s.size();0
        memo.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(4, -1)));
        return isPartitionPossible(0, 0, s, 0); 
        // startIndex, endIndex, input string, total non-overlapping palindromic                substring found
    }
};
