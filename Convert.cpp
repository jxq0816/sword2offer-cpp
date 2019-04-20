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
        // lastNode指向双向链表的尾结点
        TreeNode* lastNode =NULL;
        TreeNode* headNode=ConvertNode(pRootOfTree, lastNode);
        // headNode指向根节点root，往左移动到链表的头结点
        while (headNode != NULL && headNode->left != NULL) {
            headNode = headNode->left;
        }
        return headNode;

    }
    // 该算法没有返回链表头，而是返回了root
    TreeNode* ConvertNode(TreeNode* rootTree, TreeNode* lastNode) {
        if (rootTree == NULL) {
            return NULL;
        }
        // 转换左子树
        if (rootTree->left != NULL) {
            lastNode=ConvertNode(rootTree->left, lastNode);
        }
        // 与根节点的衔接
        rootTree->left = lastNode;
        if (lastNode != NULL) {
            lastNode->right = rootTree;
        }
        lastNode = rootTree;
        // 转换右子树
        if (rootTree->right != NULL) {
            lastNode=ConvertNode(rootTree->right, lastNode);
        }
        return lastNode;
    }
};