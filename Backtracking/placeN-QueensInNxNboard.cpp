/* The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

class Solution {
public:
    void add(vector<string> board, vector<vector<string>>& ans, int n) {
        vector<string> temp;

        for(int i = 0; i <  n; i++) {
            temp.push_back(board[i]);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<string>& board, int n) {
        int x = row;
        int y = col;

        //check for same row
        while(y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            y--;
        }

        x = row;
        y = col;

        //check for diagonal
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 'Q')
                return false;
            x--;
            y--;
        }

        x = row;
        y = col;

        while(y >= 0 && x < n) {
            if(board[x][y] == 'Q')
                return false;
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<string>& board, int n) {
        if(col == n){
            add(board, ans, n);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col+1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string x = "";
        for(int i = 0; i < n; i++) {
            x += '.';
        }  
        vector<string> board(n, x);
        vector<vector<string>> ans;

        int col = 0;
        solve(col, ans, board, n);

        return ans;

    }
};