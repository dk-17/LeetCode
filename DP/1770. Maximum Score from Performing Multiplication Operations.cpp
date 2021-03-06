class Solution {
public:
    
    int solve(vector<vector<int>>& dp,int index,vector<int> & m,int i  ,vector<int>& nums){
        if(index == m.size()) return 0;
       
        if(dp[index][i]!=-1) return dp[index][i];
         int j = nums.size()-1-(index-i);
        return dp[index][i]= max(m[index]*nums[i]+solve(dp,index+1,m,i+1,nums),m[index]*nums[j]+solve(dp,index+1,m,i,nums));
    }
    
    
    
    int maximumScore(vector<int>& nums, vector<int>& m) {
        int n = nums.size();
        vector<vector<int>> dp(1001,vector<int>(1001, -1));
        return solve(dp, 0 ,m ,0,nums);
        
    }
};
