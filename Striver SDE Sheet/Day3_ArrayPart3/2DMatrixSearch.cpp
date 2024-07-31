// 74. Search in a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/
// https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        
        // Check if the target is outside the bounds of the matrix
        if (target < matrix[0][0] || target > matrix[n-1][m-1]) {
            return false;
        }
        
        // Staircase search
        int i = 0;
        int j = m - 1;
        
        while (i <= n - 1 && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        
        return false;
    }
};
