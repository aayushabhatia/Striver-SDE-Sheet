// https://www.youtube.com/watch?v=NXOOYYwpbg4&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=2

// 1. gfg
// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        vector<int> ans;
        stack<int> s;
        for(int i = arr.size()-1; i>=0; i--){
            if(s.size()==0){
                ans.push_back(-1);
            }
            else if(s.size()>0 && s.top()>arr[i]){
                ans.push_back(s.top());
            }
            else if(s.size()>0 && s.top()<=arr[i]){
                while(s.size()>0 && s.top()<=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(s.top()); // when s.top()>arr[i] condition is reached
                }
            }
            s.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 2. leetcode (a little different)
// https://leetcode.com/problems/next-greater-element-i/description/

// Run the NGE logic on nums2. Store the result (next greater of each element in nums2) in a map. Use that map to get results for nums1.
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp; // stores next greater for each num in nums2
        vector<int> ans;
        stack<int> s;
        for(int i = nums2.size()-1; i>=0; i--){
            if(s.size()==0){
                mp[nums2[i]] = -1;
            }
            else if(s.size()>0 && s.top()>nums2[i]){
                mp[nums2[i]] = s.top();
            }
            else if(s.size()>0 && s.top()<=nums2[i]){
                while(s.size()>0 && s.top()<=nums2[i]){
                    s.pop();
                }
                if(s.size()==0){
                    mp[nums2[i]] = -1;
                }
                else{
                    mp[nums2[i]] = s.top(); // when s.top()>nums2[i] condition is reached
                }
            }
            s.push(nums2[i]);
        }
        // now mapping ans from mp
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};
