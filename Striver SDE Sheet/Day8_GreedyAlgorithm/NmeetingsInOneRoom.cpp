class Solution {
  public:
    struct Meeting{
        int start;
        int end;
        int index;
    };
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<Meeting> meetings;
        
        // Step 1: Create meeting objects
        for(int i = 0; i<n; i++){
            meetings.push_back({start[i], end[i], i+1});
        }
        // Step 2: Sort meetings by end time
        sort(meetings.begin(), meetings.end(),[](Meeting a, Meeting b){
            return a.end < b.end;
        });
        // Step 3: Greedily select meetings
        int count = 0;
        int endLimit=-1;
        for(int i=0 ; i<n; i++){
            if(meetings[i].start > endLimit){
                count++;
                endLimit = meetings[i].end;
            }
        }
        return count;
    }
};
