// 118. Pascal's Triangle
// Given an integer numRows, return the first numRows of Pascal's triangle.

// https://leetcode.com/problems/pascals-triangle/
// https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
   
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        //store the entire pascal's triangle:
        for (int row = 1; row <= numRows; row++) {
            ans.push_back(generateRow(row));
        }
        return ans;
    }

};