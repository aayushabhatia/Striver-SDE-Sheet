// 121. Best time to buys and sell stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// https://takeuforward.org/data-structure/stock-buy-and-sell/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
    int n = prices.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    
    return maxPro;
    }
};