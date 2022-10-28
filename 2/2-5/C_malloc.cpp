/*C의 동적할당 malloc, free*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char * MakeStrAdr (int len){
    char *str = (char *)malloc(sizeof(char)*len);
    return str;
}

int main(){
    char *str = MakeStrAdr(20);
    strcpy(str, "I am very happy");
    cout<<str<<endl;
    free(str);
    return 0;
}

//C언어의 malloc
//단점:
//1) malloc은 반드시 바이트 단위로 해줘야 함
//2) malloc의 반환형이 void*이기 때문에 형변환을 해줘야 함

//C++은 malloc을 new, free를 delete로 사용