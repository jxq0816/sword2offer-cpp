//
// Created by jiangxingqi on 2019/4/17.
//
#include <iostream>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL){
            return NULL;
        }
        ListNode* reverseHead = NULL;
        // 指针1：当前节点
        ListNode* currentNode = pHead;
        // 指针2：当前节点的前一个节点
        ListNode* prevNode = NULL;
        while(currentNode != NULL){
            // 指针3：当前节点的后一个节点
            ListNode* nextNode = currentNode->next;
            if(nextNode == NULL)
            {
                reverseHead = currentNode;
            }
            // 指针翻转
            currentNode->next = prevNode;
            // 将前一个节点指向当前节点
            prevNode = currentNode;
            // 将当前节点指向后一个节点
            currentNode = nextNode;
        }
        return reverseHead;
    }
};