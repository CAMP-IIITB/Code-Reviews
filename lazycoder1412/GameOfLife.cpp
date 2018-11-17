class Solution {
public:
    bool isvalid(int x,int y,int rows,int cols){
        if(x<0 or x>=rows or y>=cols or y<0)
            return false;
        return true;
    }
    int count(vector<vector<int>>& board,int r,int c,int val){
        int rows=board.size();
        int cols=board[0].size();
        int ans=0;
        if(isvalid(r-1,c,rows,cols)) {
            if(board[r-1][c]==val or board[r-1][c]==val+2)
                ans++;
        }
        if(isvalid(r+1,c,rows,cols)){
            if(board[r+1][c]==val or board[r+1][c]==val+2)
                ans++;
        }
        if(isvalid(r,c-1,rows,cols)){
            if(board[r][c-1]==val or board[r][c-1]==val+2)
                ans++;
        }
        if(isvalid(r,c+1,rows,cols)){
            if(board[r][c+1]==val or board[r][c+1]==val+2)
                ans++;
        }
        if(isvalid(r-1,c-1,rows,cols)) {
            if(board[r-1][c-1]==val or board[r-1][c-1]==val+2)
                ans++;
        }
        if(isvalid(r-1,c+1,rows,cols)){
            if(board[r-1][c+1]==val or board[r-1][c+1]==val+2)
                ans++;
        }
        if(isvalid(r+1,c+1,rows,cols)){
            if(board[r+1][c+1]==val or board[r+1][c+1]==val+2)
                ans++;
        }
        if(isvalid(r+1,c-1,rows,cols)){
            if(board[r+1][c-1]==val or board[r+1][c-1]==val+2)
                ans++;
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int rows=board.size();
        if(rows==0)
            return;
        int cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==0){
                    int cnt=count(board,i,j,1);
                    if(cnt==3)
                        board[i][j]=2;
                }
                else if(board[i][j]==1){
                    int cnt=count(board,i,j,1);
                    if(cnt<2)
                        board[i][j]=3;
                    else if(cnt>3)
                        board[i][j]=3;
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]==2)
                    board[i][j]=1;
                else if(board[i][j]==3)
                    board[i][j]=0;
            }
        }
    }
};
