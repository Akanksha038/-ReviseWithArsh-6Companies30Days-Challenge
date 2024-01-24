class Solution {
   public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        int m = board.size();
        int n = board[0].size();  // dimensions for board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    if ((i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.')) {
                        // check if cell is a leader
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};