// https://www.naukri.com/code360/problems/search-in-infinite-sorted-0-1-array_696193?leftPanelTabValue=PROBLEM
// https://www.youtube.com/watch?v=8x6dmO6XW8k&list=PL_z_8CaSLPWeYfhtuKHj-9MpYb6XQJ_f2&index=14

/************************************************************

    Use get function that returns the value at index i
    in the infinite sorted binary array.

    get(i)
    {

    }
    

************************************************************/

long long firstOne(){
    long long start = 0;
    long long end = 1;
    while(get(end)==0){
        start = end;
        end = end*2;
    }
    long long res = end;
    while(start<=end){
        long long mid = start + ((end-start)/2);
        if(get(mid)==1){
            res = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return res;
}
