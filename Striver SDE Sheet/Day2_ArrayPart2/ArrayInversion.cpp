// Inversion Of Array
// https://www.codingninjas.com/codestudio/problems/count-inversions_615
// https://takeuforward.org/data-structure/count-inversions-in-an-array/

#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=i+1 ; j<n; j++){
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}
