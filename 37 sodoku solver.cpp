#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    class cube{
    public:
        int value=-1;
        int avail[9] = {1,1,1,1,1,1,1,1,1}; //avail<=0 means not available
        int stillAvail=9;
        static int rangeLow(int a){
            if(a==0||a==1||a==2) return 0;
            if(a==3||a==4||a==5) return 3;
            if(a==6||a==7||a==8) return 6;
            std::cout<<"wrong index"<<"\n";
        }
        static int rangeHigh(int a){
            if(a==0||a==1||a==2) return 3;
            if(a==3||a==4||a==5) return 6;
            if(a==6||a==7||a==8) return 9;
            std::cout<<"wrong index"<<"\n";
        }
        static bool cube_put(int num,int x,int y,cube board[9][9]){
            board[x][y].value=num;
            int i,j;
            int flag = true;
            for(i=0;i<9;i++) {
                flag = flag && RmvPsb(num, i, y, board);
                flag = flag && RmvPsb(num, x, i, board);
                int ii,jj;
                for(ii=rangeLow(x);ii<rangeHigh(x);ii++){
                    for(jj=rangeLow(y);jj<rangeHigh(y);jj++){
                        flag = flag && RmvPsb(num,ii,jj,board);
                    }
                }

                /** this is my biggest bug. I counted also the diagonal line */
                //if (x == y) flag = flag && RmvPsb(num, i, i, board);
                //if (x + y == 8) flag = flag && RmvPsb(num, i, 8 - i, board);
            }
            return flag;
        };

        static bool RmvPsb(int num,int x,int y,cube board[9][9]){
            board[x][y].avail[num-1] -=1;
            if(board[x][y].avail[num-1]==0) board[x][y].stillAvail-=1;
            if(board[x][y].value == -1 && board[x][y].stillAvail<=0) {
                //std::cout<<"not avail at "<<x<<","<<y<<"for"<<num<<"\n";
                return false;
            }
            if(x==4&&y==4&&num==4){
                x;
            }
            return true;
        }
        static bool locale0(cube board[9][9],int &x,int &y){
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if(board[i][j].value==-1){
                        x=i;
                        y=j;
                        return true;
                    }
                }
            }
            std::cout<<"no more -1 now! \n";
            return false;
        }

        static cube (*search(cube board[9][9]))[9]{
            int x,y;
            cube a;
            if(!locale0(board,x,y)) {
                int ii,jj;
                for(ii=0;ii<9;ii++){
                    for(jj=0;jj<9;jj++){
                        std::cout<<board[ii][jj].value<<" ";
                    }
                    std::cout<<"\n";
                }
                std::cout<<"\n\n\n\n";
                return board;
            }
            /** print the current matrix */
            /*
            std::cout<<"searching for: \n";
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    std::cout<<board[i][j].value<<" ";
                }
                std::cout<<"\n";
            }
            */
            for (int i = 1; i <= 9; ++i) {
                //std::cout<<i<<"\n";
                if(board[x][y].avail[i-1]==1){
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
                    if(p!= nullptr) {return p;}
                }
            }
            cube (*nptr)[9]=nullptr;
            return nptr;
        }
    };//end of cube
    char toChar(int num){
        char z = '0';
        char res = z+num;
        return res;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int i,j;
        cube b[9][9],(*res)[9];
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(board[i][j]!='.'){
                    cube::cube_put(int(board[i][j]-'0'),i,j,b);
                }
            }
        }

        res = cube::search(b);

        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                board[i][j]= toChar(res[i][j].value);
                std::cout<<board[i][j]<<" ";
            }
            std::cout<<std::endl;
        }

    }
};

int main(){
    char s[9][9]= {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
                   {'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
                   {'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    vector<vector<char>> v(9,vector<char>(9));
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            v[i][j]=s[i][j];
        }
    }

    Solution c;
    c.solveSudoku(v);
    return 0;
}

