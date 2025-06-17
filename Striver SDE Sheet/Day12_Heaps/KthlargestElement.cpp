// https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/
// https://www.youtube.com/watch?v=4BfL2Hjvh8g&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=2
// https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/1667201117/

// Kth largest -  use min heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minh; // way to define min heap
        // priority_queue<int> maxh;   way to define max heap
        for(int i=0; i<nums.size(); i++){
            minh.push(nums[i]);
            if(minh.size()>k){
                minh.pop();
            }
        }
        return minh.top();
    }
};
