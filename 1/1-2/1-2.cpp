/* 함수 오버로딩 */
// c++이 함수를 찾는 방법은: 함수명을 확인하고 매개변수를 확인한다
// 즉, 매개변수가 다르면 함수명이 같아도 상관없다는 것
#include <iostream>

void MyFunc(){
    std::cout<<"MyFunc() called"<<std::endl;
}

void MyFunc(char c){
    std::cout<<"MyFunc(char c) called"<<std::endl;
}

void MyFunc(int a, int b){
    std::cout<<"MyFunc(int a, int b) called"<<std::endl;
}

int main(){
    MyFunc();
    MyFunc('A');
    MyFunc(12, 13);
    return 0;
}