// Order not known
// https://www.youtube.com/watch?v=gY2b-Q6wDEM&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=4

int binarySearch(int arr[], int start, int end, int x){
    // Checking the sorted order of the given array
    bool isAsc = arr[start] < arr[end];
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[middle] == x)
            return middle;

        // Ascending order
        if (isAsc == true) {
            if (arr[middle] < x)
                start = middle + 1;
            else
                end = middle - 1;
        }

        // Descending order
        else {
            if (arr[middle] > x)
                start = middle + 1;
            else
                end = middle - 1;
        }
    }
    return -1;
}
