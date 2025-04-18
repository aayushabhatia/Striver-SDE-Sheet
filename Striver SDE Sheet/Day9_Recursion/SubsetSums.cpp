// https://www.geeksforgeeks.org/problems/subset-sums2234/1
class Solution {
  public:
      void func(int ind, int sum, vector<int> arr, int N, vector<int> &SubsetSum){
          // base case
          if(ind == N){
              SubsetSum.push_back(sum);
              return;
          }
          // picking element
          func(ind+1, sum+arr[ind], arr, N, SubsetSum);
          // not picking element
          func(ind+1, sum, arr, N, SubsetSum);
      }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> SubsetSum;
        int N = arr.size();
        func(0, 0, arr, N, SubsetSum);
        sort(SubsetSum.begin(), SubsetSum.end());
        return SubsetSum;
    }
};
