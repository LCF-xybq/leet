class Solution {
public:
    bool allx(string str) {
        for (auto ch : str)
            if (ch != 'X') return false;
        return true;
    }

    bool row(vector<string> board) {
        int x = 0;
        for (auto str : board) {
            if (allx(str)) x++;
        }
        if (x > 0) return false;
        return true;
    }

    bool col(vector<string> board) {
        int x = 0;

        if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') x++;
        if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') x++;
        if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') x++;

        if (x > 0) return false;
        return true;
    }

    bool crossX(vector<string> board) {
        int oth = 0;
        if (board[1][1] == 'X') {
            if (board[0][2] == 'X' && board[2][0] == 'X') oth++;
            if (board[0][0] == 'X' && board[2][2] == 'X') oth++;
        }

        if (oth > 0) return false;
        return true;
    }

    bool corssO(vector<string> board) {
        int oth = 0;
        if (board[1][1] == 'O') {
            if (board[0][2] == 'O' && board[2][0] == 'O') oth++;
            if (board[0][0] == 'O' && board[2][2] == 'O') oth++;
        }

        if (oth > 0) return false;
        return true;
    }

    bool other(vector<string> board) {
        int o = 0, oth = 0;

        if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') o++;
        if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') o++;
        if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') o++;

        if (o > 0) return false;

        if (board[1][1] == 'O') {
            if (board[0][2] == 'O' && board[2][0] == 'O') oth++;
            if (board[0][0] == 'O' && board[2][2] == 'O') oth++;
        }

        if (oth > 0) return false;
        return true;
    }

    bool validTicTacToe(vector<string>& board) {
        int x = 0, o = 0;
        for (auto str : board) {
            for (auto ch : str) {
                if (ch == 'X') x++;
                if (ch == 'O') o++;
            }
        }

        // cout << x << endl << o << endl;

        if (x == 0 && o == 0) return true;
        if (o == 1 && x == 0) return false;
        if (x == o) {
            if (!row(board)) return false;
            if (!col(board)) return false;
            if (!crossX(board)) return false;
        } else if ((x - o) == 1) {
            if (!other(board)) return false;
        }
        if ((x - o) != 0 && (x - o) != 1) return false;

        return true;
    }
};
