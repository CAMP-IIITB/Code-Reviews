class Solution {
public:
    vector<string> ans;
    void backtrack(string temp, int open , int close, int n){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return ;
        }
        if(open>close)
            backtrack(temp+')',open, close+1,n);
        if(open<n)
            backtrack(temp+'(', open+1, close, n);
    }
    vector<string> generateParenthesis(int n) {
        backtrack("", 0,0,n);
        return ans;
    }
};
