// circular array

// https://takeuforward.org/data-structure/next-greater-element-using-stack/
// https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i = 2*n-1; i>=0; i--){
            int curr = arr[i%n];
            if(s.size()==0){
                // ans already initialised to -1
            }
            else if(s.size()>0 && s.top()>curr){
                if (i<n) ans[i] = s.top();
            }
            else if(s.size()>0 && s.top()<=curr){
                while(s.size()>0 && s.top()<=curr){
                    s.pop();
                }
                if(s.size()==0){
                    // initialised to -1
                }
                else{
                    if (i<n) ans[i] = s.top(); // when s.top()>arr[i] condition is reached
                }
            }
            s.push(curr);
        }
        return ans;
    }
};
