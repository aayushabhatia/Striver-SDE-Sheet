// https://www.geeksforgeeks.org/problems/rotation4723/1 
// https://www.youtube.com/watch?v=4WmTRFZilj8&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=7

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        
        int n = arr.size();
        int start = 0;
        int end = n-1;
        
        while(start<=end){
            
            int mid = start + ((end-start)/2);
            int next = ((mid+1) % n);
            int prev = ((mid+n-1) % n);
            
            if (arr[start] <= arr[end])
                return start;
            
            if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
                return mid;
            }
            if(arr[start] <= arr[mid]){
                start = mid+1;
            }
            else{ // for condition of (arr[mid] < arr[end])
                end = mid-1;
            }
        }
        return 0;
    }
};
