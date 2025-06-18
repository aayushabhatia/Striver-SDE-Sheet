// https://www.youtube.com/watch?v=hLR5aMzYGGk&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=7
// https://leetcode.com/problems/sort-array-by-increasing-frequency/submissions/1668116242/

class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second; // sort by value descending
            return a.first > b.first; // sort by frequency ascending
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue <pair<int,int>, vector<pair<int, int>>, cmp> minh;
        for(auto i=mp.begin(); i!=mp.end(); i++){
            minh.push({i->second, i->first});
        }
        vector<int> ans;
        while(minh.size()>0){
            int freq = minh.top().first;
            int element = minh.top().second;
            for(int i=1; i<=freq; i++){
                ans.push_back(element);
            }
            minh.pop();
        }
        return ans;
    }
};
