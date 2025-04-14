
struct Item{
    int value;
    int weight;
};
static bool comparison(Item a, Item b){
    double r1 = (double)a.value/(double)a.weight;
    double r2 = (double)b.value/(double)b.weight;
    return r1>r2;
}
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<Item> items;
        for(int i=0; i<n; i++){
            items.push_back({val[i], wt[i]});
        }
        sort(items.begin(), items.end(), comparison);
        
        int curWeight =0; 
        double totalVal=0.0;
        
        for(int i=0; i<n; i++){
            if(curWeight + items[i].weight <= capacity){
                curWeight += items[i].weight;
                totalVal += items[i].value;
            }
            else{
                int remain = capacity - curWeight;
                totalVal += (items[i].value * (double)remain)/(double)items[i].weight;
                break;
            }
        }
        return round(totalVal * 1e6) / 1e6;
        
    }
};
