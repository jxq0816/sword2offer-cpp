class Solution {
public:
    void replaceSpace(char *str,int length) {
        int i=0,cnt=0,j=0;
        while(str[i]!='\0'){
            if(str[i]==' '){
                cnt++;
            }
            i++;
        }
        j=i+cnt*2;
        str[j--]='\0';
        i--;
        while(j>0&&i>=0){
            if(str[i]!=' '){
                str[j--]=str[i];
            }else{
                str[j--]='0';
                str[j--]='2';
                str[j--]='%';
            }
            i--;
        }
    }
};