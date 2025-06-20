// https://www.youtube.com/watch?v=p9T-fE1g1pU&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=6
// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int> v;
        stack<pair<int,int>> s;
        for(int i=0; i<arr.size(); i++){
            if(s.size()==0){
                v.push_back(-1);
            }
            else if(s.size()>0 && s.top().first > arr[i]){
                v.push_back(s.top().second);
            }
            else if(s.size()>0 && s.top().first <= arr[i]){
                while(s.size()>0 && s.top().first <= arr[i]){
                    s.pop();
                }
                if(s.size()==0){
                    v.push_back(-1);
                }
                else{
                     v.push_back(s.top().second);
                }
            }
            s.push({arr[i],i});
        }
        
        for(int i=0; i<v.size(); i++){
            v[i] = i-v[i];
        }
        return v;
    }
};
