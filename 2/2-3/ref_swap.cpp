#include <iostream>
using namespace std;

// 참조자를 통한 call by reference
void SwapByRef(int &ref1, int &ref2){
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main(){
    int num1 = 2;
    int num2 = 3;
    SwapByRef(num1, num2);
    
    cout << num1 << endl;
    cout << num2;
}