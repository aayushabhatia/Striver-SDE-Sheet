// https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
// https://www.youtube.com/watch?v=X45c37QMdX0&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=12

// same approach as ceil
class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char x) {
        int start = 0;
        int end = arr.size()-1;
        char res = arr[0];
        while(start<=end){
            int mid = start + ((end-start)/2);
            if(arr[mid] == x){
                // here mid is not stored as if 'c' is target x and 'c' is present in arr and we need to find its next element so 'c' is not returned, instead 'd' is returned as arr=['c', 'd', 'f']
                start = mid+1;
            }
            else if(arr[mid]>x){
                res = arr[mid];
                end = mid-1;
            }
            else{ // arr[mid]<x
                start = mid+1;
            }
        }
        return res;
    }
};
