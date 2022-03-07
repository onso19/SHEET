class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost,int i, vector<int> &v) {
        if(v[i]!=-1)return v[i];
        if(i==0 || i==1) return 0;
        return v[i]=min(minCostClimbingStairs(cost,i-2,v)+cost[i-2],minCostClimbingStairs(cost,i-1,v)+cost[i-1]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> v(cost.size()+1,-1);
        
        return minCostClimbingStairs(cost,cost.size(),v);
    }
};
