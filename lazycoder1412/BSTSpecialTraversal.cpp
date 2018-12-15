/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int printKthLevel(TreeNode* root, int k) {
        TreeNode * currLeft = root;
        TreeNode * currRight = root;

        unordered_map<TreeNode *, int> level;	//To Store the level of Node
        unordered_map<TreeNode *, bool> checkLeft, checkRight; //To check if both left and right child have been traversed or not for both the stacks.

        stack<TreeNode * > leftStack, rightStack;
        int currLeftLevel = 1, currRightLevel = 1;
        int prevLeftVal = INT_MIN, prevRightVal = INT_MAX;
        bool currLeftDone = false, currRightDone = false, done = false; 
        
	while(true){
	    // To Print the Next Largest Element
            currLeftDone = false;
            while(currLeftDone == false){
                
		while(currLeft != NULL){
                    leftStack.push(currLeft);
                    level[currLeft] = currLeftLevel;
                    if(currLeftLevel == k){
                        if(currLeft -> val < prevRightVal){  //To check if we reached the middle value, i.e the RightStack has also printed this.
                            cout << currLeft -> val << endl;
                            currLeftDone = true;
                        }
                        prevLeftVal = currLeft -> val;
                        currLeft = NULL;
                        break;
                    }
                    checkLeft[currLeft] = true;
                    currLeft = currLeft -> left;
                    currLeftLevel ++;
                }

                while(!leftStack.empty() and (checkLeft[leftStack.top()] == false or leftStack.top() -> right == NULL))
                        leftStack.pop();
                if(leftStack.empty()){
                    done = true;
                    break;
                }
                checkLeft[leftStack.top()] = false; //Here False denotes both the children have been added into the left Stack.
                currLeftLevel = level[leftStack.top()] + 1;
                currLeft = leftStack.top() -> right;
            }
            if(done == true)
                break;

	    //To print the Next Smallest Element
            currRightDone = false;
            while(currRightDone == false){
                
		while(currRight != NULL){
                    rightStack.push(currRight);
                    level[currRight] = currRightLevel;
                    if(currRightLevel == k){
                        if(currRight -> val > prevLeftVal)  // To check if we reached the middle value, i.e the leftStack has also printed this.
                            cout << currRight -> val << endl;
                        prevRightVal = currRight -> val;
                        currRight = NULL;
                        break;
                    }
                    checkRight[currRight] = true;
                    currRight = currRight -> right;
                    currRightLevel ++;
                }

                while(!rightStack.empty() and (checkRight[rightStack.top()] == false or rightStack.top() -> left == NULL))
                    rightStack.pop();
                if(rightStack.empty()){
                    done = true;
                    break;
                }
                checkRight[rightStack.top()] = false;
                currRightLevel = level[rightStack.top()] + 1;
                currRight = rightStack.top() -> left;
            }
            if(done == true)
                break;
        }
        return 0;    
    }
};
