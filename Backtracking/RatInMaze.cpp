#include <bits/stdc++.h> 

bool isSafe(int x, int y, vector<vector<bool>> &visited, vector<vector<int>>& arr, int n){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] != 1 && arr[x][y] == 1)
        return true;
    return false;
}
void solve(int i, int j, vector<vector<int>>& arr, int n, vector<string>& ans, 
vector<vector<bool>> &visited, string path) {
    //base case
    if(i == n-1 && j == n-1){
        ans.push_back(path);
        return;
    }
    
    visited[i][j] = 1;
    //down movement
    if(isSafe(i+1, j, visited, arr, n)) {
        solve(i+1, j, arr, n, ans, visited, path + 'D');
    }

    //left movement
    if(isSafe(i, j-1, visited, arr, n)) {
        solve(i, j-1, arr, n, ans, visited, path + 'L');
    }

    //right movement
    if(isSafe(i, j+1, visited, arr, n)) {
        solve(i, j+1, arr, n, ans, visited, path + 'R');
    }

    //up movement
    if(isSafe(i-1, j, visited, arr, n)) {
        solve(i-1, j, arr, n, ans, visited, path + 'U');
    }
    visited[i][j] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {

    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n,0));
    string path = "";
    
    if(arr[0][0] == 0)
        return ans;
        
    int i = 0, j = 0;
    solve(i, j, arr, n, ans, visited, path);
    return ans;
}