//
// Created by jiangxingqi on 2020/3/18.
//
#include <iostream>
#include <stack>
#include <string.h>
#include <math.h>
using namespace std;
#define INT_MIN 0x80000000

int fun(int* p,int m,int n){
    if (p == NULL || sizeof(p) == 0 || sizeof(p[0]) == 0) {
        return 0;
    }
    int rs = INT_MIN;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                if (i != j) {
                    *(p+i*n+k)+=*(p+j*n+k);
                }
                sum += *(p+i*n+k);
                rs = max(rs, sum);
                sum = sum > 0 ? sum : 0;
            }
        }
    }
    return rs;
}


int main() {
    int array[4][4] = {{0,-2,-7,0},{9,2,-6,2},{-4,1,-4,1},{-1,8,0,-2}};
    int rs=fun(reinterpret_cast<int *>(array), 4, 4);
    cout<<"最大和为"<<rs;
}

