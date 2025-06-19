// https://www.geeksforgeeks.org/dsa/k-largestor-smallest-elements-in-an-array/
// https://www.youtube.com/watch?v=3DdP6Ef8YZM&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=3
// https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        vector<int> ans;
        for(int i=0; i< arr.size(); i++){
            minh.push(arr[i]);
            if(minh.size()>k){
                minh.pop();
            }
        }
        while(minh.size()>0){
            ans.push_back(minh.top());
            minh.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
