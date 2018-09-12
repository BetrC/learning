//
// Created by Betr on 2018/9/11.
//
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {


        vector<int> _print;

        if(root == NULL){
            return _print;
        }

        // the queue to store every node
        queue<TreeNode*> q;

        q.push(root);
        while (q.size() != 0){

            TreeNode* node = q.front();
            _print.push_back(node->val);
            if(node->left != NULL)
            {
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }

            q.pop();
        }

        return _print;
    }
};