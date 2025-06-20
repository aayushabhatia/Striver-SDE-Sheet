// https://www.youtube.com/watch?v=nc1AYFyvOR4&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=5&pp=iAQB

class Solution {
  public:
    vector<int> rightSmaller(vector<int> arr) {
        vector<int> ans;
        stack<int> s;
        for(int i=arr.size()-1; i>=0; i--){
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
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
