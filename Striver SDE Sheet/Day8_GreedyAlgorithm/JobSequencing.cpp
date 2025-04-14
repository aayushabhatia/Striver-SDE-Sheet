struct Job{
    int id;
    int deadline;
    int profit;
};

static bool comparison (Job a, Job b){
            return (a.profit > b.profit);
}

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n= deadline.size();
        vector<Job> jobs;
        
        for(int i=0; i<n; i++){
            jobs.push_back({i, deadline[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end(), comparison);
        
        int maxDeadline = *max_element(deadline.begin(), deadline.end());
        vector<int> slots(maxDeadline+1 , -1);
        
        int total_jobs = 0, max_profit = 0;
        
        for (auto &job : jobs) {
            // Try to place the job at the latest available slot before deadline
            for (int j = job.deadline; j >= 1; j--) {
                if (slots[j] == -1) {
                    slots[j] = job.id;
                    total_jobs++;
                    max_profit += job.profit;
                    break;
                }
            }
        }
        return {total_jobs, max_profit};

    }
};
