// https://leetcode.com/problems/combination-sum-ii/
// https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/

class Solution {
public:
    void findSubsets(int ind, vector<int> &candidates, vector<int> &ds, int target, vector<vector<int>> &ans){
        
            if(target==0){
                ans.push_back(ds);
                return;
            }
            
        
        //picking element
        for (int i = ind; i < candidates.size(); i++) {
    if (i > ind && candidates[i] == candidates[i - 1]) continue;
    if (candidates[i] > target) break;
    ds.push_back(candidates[i]);
    findSubsets(i + 1, candidates, ds,  target - candidates[i], ans);
    ds.pop_back();
  }

        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(0, candidates, ds, target, ans);
        return ans;
    }
};
