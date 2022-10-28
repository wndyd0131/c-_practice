/*CPP의 동적할당 new와 delete*/

#include <iostream>
#include <string.h>
using namespace std;

char *MakeStrAdr(int len){
    char *str = new char[len];
    return str;
}

int main(){
    char *str = MakeStrAdr(20);
    strcpy(str, "I am very happy");
    cout<<str<<endl;
    delete []str;
    return 0;
}

/*
int *ptr = new int;
int *arr = new int[20];
    - == malloc(sizeof(int) * 20);
delete ptr;
delete []arr;
    - == free(arr);

참조자를 통해 포인터 연산없이 힙에 접근
    -  
        int *ptr = new int;
        int &ref = *ptr;
        ref = 20;
*/