class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        for (auto i = 1; i < 6; i++)
        {
            board[0][i] += board[0][i-1];
            board[i][0] += board[i-1][0];
        }
        for (auto i = 1; i < 6; i++)
        {
            for (auto j = 1; j < 6; j++)
            {
                board[i][j] += (max(board[i-1][j], board[i][j-1]));
            }
        }
        return board[5][5];
    }
};
