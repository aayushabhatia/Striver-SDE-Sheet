// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
// https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/

class Solution {
  public:
    // return 0 if ans < m
    // return 1 if ans == m
    // return 2 if ans > m
    int func(int mid, int m, int n){
        long long ans = 1;
        for(int i=0; i<n; i++){
            ans = ans * mid;
            if(ans>m) return 2;
        }
        if(ans<m) return 0;
        return 1;
    }
    int nthRoot(int n, int m) {
        int low=1, high=m;
        while(low<=high){
            int mid=(low+high)/2;
            int midN = func(mid, m , n);
            if(midN==1){
                return mid;
            }
            else if(midN==0) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};
