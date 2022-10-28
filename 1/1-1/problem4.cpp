#include <iostream>
int main(){
    int price;
    while(1){
        std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin>>price;
        if(price == -1) break;
        else std::cout<<"이번 달 급여: "<<50+price*0.12<<"만원";
    }
}