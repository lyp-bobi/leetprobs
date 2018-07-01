#include <vector>
#include <iostream>

using std::vector;

class Solution {
    class cube{
    public:
        int value=-1;
        int avail[10] = {1,1,1,1,1,1,1,1,1,1}; //avail<=0 means not available
        int stillAvail=10;
        static bool cube_put(int num,int x,int y,cube board[9][9]){
            board[x][y].value=num;
            int i,j;
            int flag = true;
            for(i=0;i<9;i++) {
                flag = flag && RemPossi(num, i, y, board);
                flag = flag && RemPossi(num, x, i, board);
                if (x == y) flag = flag && RemPossi(num, i, i, board);
                if (x + y == 8) flag = flag && RemPossi(num, i, 8 - 1, board);
            }
            return flag;
        }
        static bool RemPossi(int num,int x,int y,cube board[9][9]){
            board[x][y].avail[num] -=1;
            if(board[x][y].avail[num]==0) board[x][y].stillavail-=1;
            if(stillavail<=0) return false;
            return true;
        }
        static bool locale0(cube board[9][9],int &x,int &y){
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if(board[i][j]!=-1){
                        x=i;
                        y=j;
                        return true;
                    }
                }
            }
            return false;
        }

        static auto search(cube board[9][9]){
            int x,y;
            if(locale0(board,x,y)) return board;
            for (int i = 0; i <= 9; ++i) {
                if(board[x][y].avail[i]==1){
                    cube board_[9][9];
                    for (int j = 0; j < 9; ++j) {
                        for (int k = 0; k < 9; ++k) {
                            board_[j][k]=board[j][k];
                        }
                    }//copy a new board
                    if(cube_put(i,x,y,board_)== false){
                        continue;
                    }
                    auto p=search(board_);
                    if(p!= nullptr) return p;
                }
            }

        }
    };
public:
    void solveSudoku(vector<vector<char>>& board) {
        int i,j;
        cube b[9][9];
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(board[i][j]!="."){
                    cube.cube_put(int(board[i][j]-"0",i,j,b);
                }
            }
        }

    }
};
