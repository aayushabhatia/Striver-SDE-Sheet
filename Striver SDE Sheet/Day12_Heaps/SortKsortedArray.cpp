// https://www.geeksforgeeks.org/dsa/nearly-sorted-algorithm/
// https://www.youtube.com/watch?v=dYfM6J1y0mU&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=4
// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> minh;
        int index=0;
        for(int i=0; i< arr.size(); i++){
            minh.push(arr[i]);
            if(minh.size()>k){
                int x = minh.top();
                minh.pop();
                arr[index]=x;
                index++;
            }
        }
        while(minh.size()>0){
            int x = minh.top();
            minh.pop();
            arr[index]=x;
            index++;
        }
    }
};
