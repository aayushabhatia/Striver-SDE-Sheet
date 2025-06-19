priority_queue<int, vector<int>, greater<int>> minh; // way to define min heap
priority_queue<int> maxh;   // way to define max heap
// heap used when in ques there is k and smallest/largest is asked, feel of sorting
// max heap used in case of smallest, min heap used in case of largest
// from sorting we get time complexity of nlogn (merge sort), its optimised approach is using heap which gives nlogk time complexity where k is a given number in ques.
