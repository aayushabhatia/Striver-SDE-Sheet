// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
// https://takeuforward.org/data-structure/median-of-row-wise-sorted-matrix/

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
    vector<int> ds;
    
    int m= mat.size();
    int n=mat[0].size();
    //traverse the matrix and copy the elements to list:
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ds.push_back(mat[i][j]);
        }
    }

    //sort the list:
    sort(ds.begin(), ds.end());
    return ds[(m * n) / 2];
    }
};
