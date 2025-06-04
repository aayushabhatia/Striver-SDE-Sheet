// https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164159?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
// https://takeuforward.org/data-structure/k-th-element-of-two-sorted-arrays/

#include <climits>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    if(n>m){
        return kthElement(arr2, arr1, m, n, k); // to ensure arr1 is smaller than arr2, binary search done on smallest array for efficiency
    }
    int low=max(0,k-m), high=min(k,n);
    while(low<=high){
        int cut1= (low+high)/2;
        int cut2= k-cut1;
        int l1=cut1 == 0 ? INT_MIN : arr1[cut1-1]; // l1 and l2 are last elements of left partition
        int l2=cut2 == 0 ? INT_MIN : arr2[cut2-1];
        int r1=cut1 == n ? INT_MAX : arr1[cut1]; // r1 and r2 are first elements of right partition
        int r2=cut2 == m ? INT_MAX : arr2[cut2];

        if(l1<=r2 && l2<=r1){
            return max(l1,l2); //kth element
        }
        if(l1>r2){
            high=cut1-1; //shift left
        }
        else{
            low=cut1+1; // shift right
        }
    }
    return 1;
}
