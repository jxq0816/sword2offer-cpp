//
// Created by jiangxingqi on 2019/4/20.
//
#include <iostream>
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* lastNode =NULL;
        TreeNode* headNode=ConvertNode(pRootOfTree, lastNode);
        while (headNode != NULL && headNode->left != NULL) {
            headNode = headNode->left;
        }
        return headNode;

    }
    TreeNode* ConvertNode(TreeNode* rootTree, TreeNode* lastNode) {
        if (rootTree == NULL) {
            return NULL;
        }
        if (rootTree->left != NULL) {
            lastNode=ConvertNode(rootTree->left, lastNode);
        }
        rootTree->left = lastNode;
        if (lastNode != NULL) {
            lastNode->right = rootTree;
        }
        lastNode = rootTree;
        if (rootTree->right != NULL) {
            lastNode=ConvertNode(rootTree->right, lastNode);
        }
        return lastNode;
    }
};