// 50. Implementing Pow(x,n) ie x^n
// https://leetcode.com/problems/powx-n/
// https://takeuforward.org/data-structure/implement-powxn-x-raised-to-the-power-n/

#include<bits/stdc++.h>
using namespace std;

// Optimal Solution ( works fine when n is negative )
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) 
            nn = -1 * nn;
        while (nn) {
            if (nn % 2) {
                ans = ans * x;
                nn = nn - 1;
            } else {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};
