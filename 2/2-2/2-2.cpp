#include <iostream>
using namespace std;

// bool 자료형 사용
bool isPositive(int num){
    if(num <= 0)
    return false;
    else
    return true;
}

int main(){
    if(true == 1){
        cout << "It is true";
    }
    else{
        cout << "It is false"<< endl;
    }
}

//* true는 1로, false는 0으로 변환되지만, true가 1이고 false는 0으로 생각하면 안 됨

