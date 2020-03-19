//
// Created by jiangxingqi on 2020/3/19.
//

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> rs;
        while(head){
            int val=head->val;
            rs.insert(rs.begin(),val);
            head=head->next;
        }
        return rs;
    }
};