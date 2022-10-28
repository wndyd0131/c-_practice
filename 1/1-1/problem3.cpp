#include <iostream>
int main(){
    int num;
    std::cout<<"숫자를 입력하시오: ";
    std::cin>>num;
    for(int i = 1; i <= 9; i++){
        std::cout<<num<<" x "<<i<<" = "<<num * i<<std::endl;
    }
    return 0;
}