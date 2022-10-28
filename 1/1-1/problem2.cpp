#include <iostream>
int main(){
    char name[20];
    char tel[20];
    std::cout<<"이름: ";
    std::cin>>name;
    std::cout<<"전화번호: ";
    std::cin>>tel;
    std::cout<<"제 이름은 "<<name<<"이고, 전화번호는 "<<tel<<"입니다."<<std::endl;
}