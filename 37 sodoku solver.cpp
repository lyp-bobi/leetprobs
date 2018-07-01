class Solution {
struct cube{
    int value="-1";
    int avail[10] = {1,1,1,1,1,1,1,1,1,1}; //avail<=0 means not availlable
}
bool cube_put(int num,int x,int y,cube& board[9][9]){
    board[x][y].value=num;
    int i,j;
    for(i=0;i<9;i++){
        board[i][y].avail[num]-=1;
        board[x][i].avail[num]-=1;
    }
}
bool cube_remove(int x, int y, cube& board[9][9]){
    int num;
    num=board[x][y].value;
    for(i=0;i<9;i++){
        board[i][y].avail[num]+=1;
        board[x][i].avail[num]+=1;
    }
}
bool search(cube &board[9][9])
public:
    void solveSudoku(vector<vector<char>>& board) {
        int i,j;
        cube b[9][9];
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(board[i][j]!="."){
                    cube_put(int(board[i][j]-"0",i,j,b);
                }
            }
        }

    }
};