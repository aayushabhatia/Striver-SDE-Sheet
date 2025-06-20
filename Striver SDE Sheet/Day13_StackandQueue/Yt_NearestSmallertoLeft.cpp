// https://www.youtube.com/watch?v=85LWui3FlVk&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=4
// https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/0

class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        vector<int> ans;
        stack<int> s;
        for(int i=0; i<arr.size(); i++){
            if(s.size()==0){
                ans.push_back(-1);
            }
            else if(s.size()>0 && s.top()<arr[i]){
                ans.push_back(s.top());
            }
            else if(s.size()>0 && s.top()>=arr[i]){
                while(s.size()>0 && s.top()>=arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(s.top()); // when s.top()<arr[i] condition is reached
                }
            }
            s.push(arr[i]);
        }
        return ans;
    }
};
