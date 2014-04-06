#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > rows(9, vector<bool>(9, false));
        vector<vector<bool> > cols(9, vector<bool>(9, false));
        vector<vector<bool> > blocks(9, vector<bool>(9, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int c = board[i][j] - '1';
                if (rows[i][c] || cols[j][c] || blocks[i - i % 3 + j / 3][c])
                    return false;
                rows[i][c] = cols[j][c] = blocks[i - i % 3 + j / 3][c] = true;
            }
        }
        return true;
    }
};

int main()
{
    Solution So;
    const char *input[9] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"} ;
    vector<vector<char> > board(9);
    for (int i=0;i<9;i++)
        board[i].assign(input[i],input[i]+9);
    //intiate board
    //print board
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++)
            cout<<board[i][j]<<"\t";
        cout<<endl;
    }
    cout<<So.isValidSudoku(board)<<endl;
}
