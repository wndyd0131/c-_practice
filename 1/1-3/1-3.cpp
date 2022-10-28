/* 매개변수의 디폴트 값 */
// 함수 호출 시 인자를 전달하지 않으면 디폴트 값이 적용됨
#include <iostream>
int Adder(int num1=1, int num2=2); //이런식으로 선언부에만 디폴트값 설정해도 적용됨
//int Adder(int num1, int num2=2) o
//int Adder(int num1=1, int num2) x //이런식으로 하면 안됨, 디폴트값은 반드시 우측부터 채워져야 함

int main(){
    std::cout<<Adder()<<std::endl;
    std::cout<<Adder(5)<<std::endl;
    std::cout<<Adder(3, 5)<<std::endl;
    return 0;
}

int Adder(int num1, int num2){
    return num1 + num2;
}