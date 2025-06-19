// https://www.youtube.com/watch?v=3ioQQQrnw4Q&list=PL_z_8CaSLPWdtY9W22VjnPxG30CXNZpI9&index=10
// https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1

class Solution {
  public:
    int kthsmallest(long long *A, long long N, long long K){
        priority_queue<long long> maxh;
        long long sum = 0;
        for(int i=0; i<K; i++){
            maxh.push(A[i]);
        }
        for(int i=K; i<N; i++){
            if(A[i]<maxh.top()){
                maxh.pop();
                maxh.push(A[i]);
            }
        }
        return maxh.top();
    }
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        int first= kthsmallest(A, N, K1);
        int second= kthsmallest(A, N, K2);
        long long sum= 0;
        for (int i=0; i<N; i++){
            if(first<A[i] and second> A[i] ){
                sum= A[i]+ sum;
               
            }
        }
        return sum;
    }
};
