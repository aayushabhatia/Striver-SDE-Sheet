// https://www.youtube.com/watch?v=J2X70jj_I1o&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=7
// https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        vector<int> left, right;
        stack<pair<int,int>> s1, s2; // s1 for left, s2 for right
        int pseudo_index1 = -1;
        int pseudo_index2 = arr.size();
        
        // nsl (left)
        for(int i=0; i<arr.size(); i++){
            if(s1.size()==0){
                left.push_back(pseudo_index1);
            }
            else if(s1.size()>0 && s1.top().first<arr[i]){
                left.push_back(s1.top().second);
            }
            else if(s1.size()>0 && s1.top().first>=arr[i]){
                while(s1.size()>0 && s1.top().first>=arr[i]){
                    s1.pop();
                }
                if(s1.size()==0){
                    left.push_back(pseudo_index1);
                }
                else{
                    left.push_back(s1.top().second); // when s.top()<arr[i] condition is reached
                }
            }
            s1.push({arr[i],i});
        }
        
        // nsr (right)
        for(int i=arr.size()-1; i>=0; i--){
            if(s2.size()==0){
                right.push_back(pseudo_index2);
            }
            else if(s2.size()>0 && s2.top().first<arr[i]){
                right.push_back(s2.top().second);
            }
            else if(s2.size()>0 && s2.top().first>=arr[i]){
                while(s2.size()>0 && s2.top().first>=arr[i]){
                    s2.pop();
                }
                if(s2.size()==0){
                    right.push_back(pseudo_index2);
                }
                else{
                    right.push_back(s2.top().second); // when s.top()<arr[i] condition is reached
                }
            }
            s2.push({arr[i],i});
        }
        reverse(right.begin(), right.end());
        
        int max_area = INT_MIN;
        for(int i=0;i<arr.size();i++){
            max_area = max(max_area,(right[i]-left[i]-1)*arr[i]); // taking max after finding area
        }
        return max_area;
    }
};
