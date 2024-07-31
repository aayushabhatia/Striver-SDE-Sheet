// 74. Search in a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/
// https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/

#include<bits/stdc++.h>
using namespace std;

// Brute Force
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

// Optimal Solution- Hypothetically flatten the array
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
    }
};
