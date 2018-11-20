class Solution {
public:
    bool isValid (int x, int y, int rows, int cols) {
        if (x < 0 or x >= rows or y >= cols or y < 0)
            return false;
        return true;
    }
    int countNumAliveNeighbors(vector<vector<int>>& board, int r, int c, int val){
        int rows = board.size();
        int cols = board[0].size();
        int ans = 0;
        const int directionX = {1, -1, 0};
        const int directionY = {1, -1, 0};
        for (int x = 0; x < directionX.size(); x++) {
          for (int y = 0; y < directionY.size(); y++){
            if( x == 0 and y == 0)
              continue;
            if (isValid[r + directionX[x]][c + directionY[y]]){
              if (board[r + directionX[x]][c + directionY[y]] == val or board[r + directionX[x]][c + directionY[y]] == val + 2){
                  ans++;
              }
            }
          }
        }
        return ans;
    }
    void gameOfLife (vector< vector< int > >& board) {
        int rows = board.size();
        if(rows == 0)
            return;
        int cols = board[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (board[i][j] == 0){
                    int cnt = countNumAliveNeighbors(board, i, j, 1);
                    if(cnt == 3)
                        board[i][j] = 2;
                }
                else if (board[i][j] == 1) {
                    int cnt = countNumAliveNeighbors(board, i, j, 1);
                    if (cnt < 2)
                        board[i][j] = 3;
                    else if(cnt > 3)
                        board[i][j] = 3;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(board[i][j] == 2)
                    board[i][j] = 1;
                else if (board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }
};
