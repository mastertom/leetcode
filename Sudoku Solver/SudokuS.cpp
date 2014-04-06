#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board,int x, int y) {
        int i, j;  
        for (i = 0; i < 9; i++)  
            if (i != x && board[i][y] == board[x][y])  
                return false;  
        for (j = 0; j < 9; j++)  
            if (j != y && board[x][j] == board[x][y])  
                return false;  
        for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)  
            for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)  
                if (i != x && j != y && board[i][j] == board[x][y])  
                    return false;  
        return true;
    }
    bool solveSudoku(vector<vector<char> > &board) {
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
            {
                if (board[i][j] == '.')
                {
                    for (int k=1;k<=9;k++)
                    {
                        board[i][j] = '0' + k;
                        if (isValidSudoku(board,i,j) && solveSudoku(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
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
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    So.solveSudoku(board);
    cout<<endl<<endl;
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

