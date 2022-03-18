//Logic: Count the number of moves with insert, remove and replace operation, return minimum.
// I guess another way of (word1.length-lcs)  ight work peerfctly as well because we will do insert update and delete in those elements only whuch ar different
class Solution {
public:
    vector<vector<int>> t;
    int minDistance(string a, string b) {
        t.resize(a.size()+2, vector<int>(b.size()+2, -1));
        return helper(0, 0, a, b);
    }
    
    int helper(int i, int j, string& a, string& b){
	//Base Case: If we have reached end of one string, required no. of operations is the lenght of other remaining string.
        if(i == a.size()) return b.size()-j;
        if(j == b.size()) return a.size()-i;
        
        if(t[i][j] != -1) return t[i][j];
        if(a[i] == b[j]) return t[i][j] = helper(i+1, j+1, a, b);
        else{
            int insertMoves = 1 + helper(i, j+1, a, b); //Insert
            int removeMoves = 1 + helper(i+1, j, a, b); //Remove
            int replaceMoves = 1 + helper(i+1, j+1, a, b); //Replace
            
            return t[i][j] = min({insertMoves, removeMoves, replaceMoves});
        }
    }
};
