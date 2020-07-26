class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        if(n <= 0){
            return res;
        }
        dfs(nums,res,n,0);
        return res;
    }
    void dfs(vector<int>&nums,vector<vector<int>>&res,int n,int s){
        if(s == n){  
            res.push_back(nums);  
            return;
        }
        for(int i = s;i<n;i++){
            swap(nums[i],nums[s]);
            dfs(nums,res,n,s+1);
            swap(nums[i],nums[s]);
        }
    }
};