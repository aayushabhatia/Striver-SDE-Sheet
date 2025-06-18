// https://www.youtube.com/watch?v=7VoJn544QrM&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=6
// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minh;
        for(auto i=mp.begin(); i!=mp.end(); i++){
            minh.push({i->second, i->first});
            if(minh.size()>k){
                minh.pop();
            }
        }
        vector<int> ans;
        while(minh.size()>0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};
