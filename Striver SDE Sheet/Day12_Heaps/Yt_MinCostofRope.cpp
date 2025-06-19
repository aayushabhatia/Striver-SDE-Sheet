// https://www.youtube.com/watch?v=_k_c9nqzKN0&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=9
// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i=0; i<arr.size(); i++){
            minh.push(arr[i]);
        }
        int cost = 0;
        while(minh.size()>=2){
            int first = minh.top();
            minh.pop();
            int second = minh.top();
            minh.pop();
            cost = cost+first+second;
            minh.push(first+second);
        }
        return cost;
    }
};
