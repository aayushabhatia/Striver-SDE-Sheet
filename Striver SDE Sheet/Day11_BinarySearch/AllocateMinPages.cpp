// https://takeuforward.org/data-structure/allocate-minimum-number-of-pages/
// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution {
  public:
    int countStudents(vector<int> &arr, int pages) {
        int n = arr.size(); //size of array.
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < n; i++) {
            if (pagesStudent + arr[i] <= pages) {
                //add pages to current student
                pagesStudent += arr[i];
            }
            else {
                //add pages to next student
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        //book allocation impossible:
        if (k > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int students = countStudents(arr, mid);
            if (students > k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};
