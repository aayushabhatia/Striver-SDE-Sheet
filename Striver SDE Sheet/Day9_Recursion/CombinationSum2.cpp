// https://leetcode.com/problems/combination-sum-ii/
// https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/

class Solution {
public:
    void findSubsets(int ind, vector<int> &candidates, vector<int> &ds, int target, vector<vector<int>> &ans){
            // base case
            if(target==0){
                ans.push_back(ds);
                return;
            }
            
        
        //picking element
        for (int i = ind; i < candidates.size(); i++) {
    if (i > ind && candidates[i] == candidates[i - 1]) continue; // to avoid picking up same elements in one recursion call
    if (candidates[i] > target) break; // if arr value becomes greater than target , break the loop
    ds.push_back(candidates[i]);
    findSubsets(i + 1, candidates, ds,  target - candidates[i], ans);
    ds.pop_back(); // pop out the element for the next recursion call
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
