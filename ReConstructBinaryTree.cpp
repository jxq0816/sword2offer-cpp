#include <iostream>
using namespace std;
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
    {
        if(pre.size() != vin.size())
            return NULL;
        int rootIndex=0;
        int size = pre.size();
        if(size==0){
            return NULL;
        }
        //查找根节点在先序遍历数组中的下标
        TreeNode *treeNode=new TreeNode(pre[0]);

        for(int i=0;i<size;i++) {
            //中序遍历数组中的第一个位置是根节点
            if(vin[i]==pre[0]) {
                rootIndex=i;
                break;
            }
        }
        //将先序的遍历结果分成两份，一份是左子树，一份是右子树
        int leftlength = rootIndex;
        int rightlength = size - 1 - rootIndex;
        vector<int> preLeft(rootIndex),vinLeft(rootIndex);;
        vector<int> preRight(rightlength),vinRight(rightlength);

        // 把左右子树填写好
        for(int i = 0; i < size; i++)
        {
            if(i < rootIndex)
            {
                preLeft[i] = pre[i+1];
                vinLeft[i] = vin[i];
            }
            else if(i > rootIndex)
            {
                preRight[i-rootIndex-1] = pre[i];
                vinRight[i-rootIndex-1] = vin[i];
            }
        }
        treeNode->left=reConstructBinaryTree(preLeft,vinLeft);
        treeNode->right= reConstructBinaryTree(preRight,vinRight);
        return treeNode;
    }
    void preVisit(TreeNode* treeNode){
        if(treeNode==NULL){
            return;
        }
        cout << treeNode->val << ",";
        preVisit(treeNode->left);
        preVisit(treeNode->right);
    }
    void midVisit(TreeNode* treeNode){
        if(treeNode==NULL){
            return;
        }
        midVisit(treeNode->left);
        cout << treeNode->val << ",";
        midVisit(treeNode->right);
    }
};

int main(int argc, char* argv[])
{
    Solution *solution=new Solution();
    std::vector<int> pre={1,2,4,7,3,5,6,8};
    std::vector<int> vin={4,7,2,1,5,3,8,6};
    TreeNode* rs=solution->reConstructBinaryTree(pre,vin);
    solution->preVisit(rs);
    cout<<'\n';
    solution->midVisit(rs);
    cout<<'\n';
}
