// https://leetcode.com/problems/permutations/
// https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/

// Approach -1
class Solution {
public:
    void func(vector<int> &nums, vector<int> &ds, int mp[], vector<vector<int>> &ans){
        if(ds.size()== nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!mp[i]){
                ds.push_back(nums[i]);
                mp[i]=1;
                func(nums, ds, mp, ans);
                mp[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int mp[nums.size()];
        for(int i=0; i<nums.size(); i++){
            mp[i]=0;
        }
        func(nums, ds, mp, ans);
        return ans;
    }
};

// Approach - 2
class Solution {
public:
    void func(int ind, vector<int> &nums, vector<vector<int>> &ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind; i<nums.size(); i++){
            swap(nums[ind], nums[i]);
            func(ind+1, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        func(0, nums, ans);
        return ans;
    }
};
