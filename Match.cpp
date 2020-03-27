//
// Created by jiangxingqi on 2020/3/18.
//
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

static int check(string str){
    stack<int> s;
    char pre;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch==')' && pre=='('){
            s.pop();
        }else{
            s.push(ch);
        }
        pre=ch;
    }
    if(s.empty()){
        return 0;
    }else{
        return s.size();
    }
}

int main() {
    string test="(()()(";
    int rs=check(test);
    if(rs==0){
        cout << "合法";
    }else{
        cout << "不合法,至少添加" <<rs<<"个";
    }
}