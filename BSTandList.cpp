//
// Created by Betr on 2018/9/12.
//
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


// maintain a pre node
class Solution {
public:
    void Convert_R(TreeNode *curr, TreeNode *&pre) {
        if (!curr) return;

        Convert_R(curr->left, pre);

        // rePointing
        curr->left = pre;
        if (pre)
            pre->right = curr;
        pre = curr;

        Convert_R(curr->right, pre);
    }

    TreeNode *Convert(TreeNode *pRootOfTree) {
        if (!pRootOfTree) return NULL;

        TreeNode *pre = NULL;

        Convert_R(pRootOfTree, pre);

        while (pre->left)
            pre = pre->left;

        return pre;

    }
};