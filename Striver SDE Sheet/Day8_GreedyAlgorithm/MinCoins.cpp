// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> denomination = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector < int > ans;
        int n = denomination.size();
        for (int i = n - 1; i >= 0; i--) { // started iterating from last or biggest value  of denominations
            while (N >= denomination[i]) {
                N -= denomination[i];
                ans.push_back(denomination[i]);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
};
