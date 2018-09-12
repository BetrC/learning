//
// Created by Betr on 2018/9/12.
//

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution
{
public:
    vector< vector<int> > m_res;

    vector< vector<int> > FindPath(TreeNode* root, int expectNumber)
    {
        if(root == NULL){
            return m_res;
        }

        vector<int> path;
        __findPath(root, expectNumber, path, 0);

        return m_res;


    }

    void __findPath(TreeNode* root, int expectNum, vector<int> path, int currNum){

        currNum += root->val;
        path.push_back(root->val);

        // 注意所选路径是直到叶节点
        if(currNum == expectNum && root->left == NULL && root->right == NULL){
            m_res.push_back(path);
        }
        if(root->left != NULL){
            __findPath(root->left, expectNum, path, currNum);
        }
        if(root->right != NULL){
            __findPath(root->right, expectNum, path, currNum);
        }
    }
};