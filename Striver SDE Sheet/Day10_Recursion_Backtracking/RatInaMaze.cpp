// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// https://takeuforward.org/data-structure/rat-in-a-maze/

class Solution {
  public:
    void func(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[]){
        // base case
        if(i == n-1 && j == n-1){
            ans.push_back(move);
            return;
        }
        string dirn = "DLRU";
        for(int ind=0; ind<4; ind++){
            int nexti = i+ di[ind];
            int nextj = j+ dj[ind];
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && mat[nexti][nextj] == 1) {
                vis[i][j] = 1;
                func(nexti, nextj, mat, n, ans, move + dirn[ind], vis, di, dj);
                vis[i][j] = 0;
        }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n,0));
        int di[4]={ +1, 0, 0, -1};
        int dj[4]={ 0, -1, 1, 0};
        if(mat[0][0]==1){
           func(0, 0, mat, n, ans, "", vis, di, dj); 
        }
        return ans;
    }
};
