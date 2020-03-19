//
// Created by jiangxingqi on 2020/3/19.
//

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int i,j;
        for(i=0;i<array.size();i++){
            for(j=0;j<array[0].size();j++){
                if(target==array[i][j]){
                    return true;
                }
            }
        }
        return false;
    }
};