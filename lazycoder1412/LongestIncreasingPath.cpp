class Solution {
public:
    vector<vector<int> >val;
    bool isValid (int x, int y, int rows, int cols) {
        if (x < 0 or x >= rows or y < 0 or y >= cols)
            return false;
        return true;
    }
    int backtrack (vector<vector<int> >& matrix, int i, int j, int last) {
        if (val[i][j] != 0)
           return val[i][j];
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0;
        const int dirX = {-1, 1, 0, 0};
        const int dirY = {0, 0, -1, 1};
        for(int dir = 0; dir < dirX.size(); dir++){
          if(isValid(i + dirX[dir], j + dirY[dir], rows, cols)){
            if( matrix[i + dirX[dir]][j + dirY[y]] > last){
              ans = max(ans, backtrack(matrix, i + dirX[dir], j + dirY[dir], matrix[i + dirX[dir]][j + dirY[dir]]));
            }
          }
        }
        val[i][j] = ans + 1;
        return val[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return 0;
        int cols = matrix[0].size();
        int i = 0, j = 0;
        val.resize(rows, vector<int>(cols, 0));
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans=max(ans, backtrack(matrix, i, j, matrix[i][j]));
            }
        }
        return ans;
    }
};
