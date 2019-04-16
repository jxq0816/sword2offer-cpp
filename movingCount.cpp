//
// Created by jiangxingqi on 2019/4/16.
//
#include <iostream>
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool* visited = new bool[rows*cols];
        memset(visited, 0, rows*cols);
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
        delete[]visited;
        return count;
    }
    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        int count = 0;
        if (check(threshold, rows, cols, row, col, visited))
        {
            visited[row*cols + col] = true;
            count = 1 + movingCountCore(threshold, rows, cols, row, col - 1, visited) +
                    movingCountCore(threshold, rows, cols, row - 1, col, visited) +
                    movingCountCore(threshold, rows, cols, row, col + 1, visited) +
                    movingCountCore(threshold, rows, cols, row + 1, col, visited);
        }
        return count;
    }

    /*该函数检查坐标为(row,col)的方格能够进入*/
    bool check(int threshold, int rows, int cols, int row, int col, bool*visited)
    {
        if (row >= 0 && row < rows&&col >= 0 && col < cols
            &&getDigitSum(row) + getDigitSum(col) <= threshold
            && !visited[row*cols + col])
            return true;
        return false;
    }

    /*计算一个数的所有位数之和*/
    int getDigitSum(int number)
    {
        int sum = 0;
        while (number > 0)
        {
            sum += number % 10;
            number = number / 10;
        }
        return sum;
    }
};
int main() {
    Solution *ss=new Solution();
    int count = ss->movingCount(4,10,10);
    std::cout << count << std::endl;
    return 0;
}