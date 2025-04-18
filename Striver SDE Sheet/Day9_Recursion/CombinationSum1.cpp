// https://leetcode.com/problems/combination-sum/
// https://takeuforward.org/data-structure/combination-sum-1/

class Solution {
public:
    void findSubsets(int ind, vector<int> &candidates, vector<int> &ds, int target, vector<vector<int>> &ans){
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        //picking element
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            findSubsets(ind, candidates, ds, target - candidates[ind], ans);
            ds.pop_back();
        }

        //not picking
        findSubsets(ind+1, candidates, ds, target, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(0, candidates, ds, target, ans);
        return ans;
    }
};
