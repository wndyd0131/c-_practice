#include <iostream>
#include <cstring>
using namespace std;

class Base{
    public:
    void BaseFunc(){

    }
};

class Derived: public Base{
    public:
    void DerivedFunc(){

    }
};

class First{
    public:
    virtual void myFunc(){
        cout<<"First"<<endl;
    }
};
class Second:public First{
    public:
    virtual void myFunc(){
        cout<<"Second"<<endl;
    }
};
class Third:public Second{
    public:
    virtual void myFunc(){
        cout<<"Third"<<endl;
    }
};
int main(){
    Base *bptr = new Derived();
    bptr->BaseFunc();
//    bptr->DerivedFunc(); //컴파일 에러
//    Derived *dptr = bptr; //컴파일 에러
// C++ 컴파일러는 포인터 연산의 가능 여부를 포인터의 자료형 기준으로 판단
    Third *tptr = new Third();
    Second *sptr = tptr; //리모콘이 리모콘을 가리킴
    First *fptr = sptr;
    // virtual로 인해 자료형이 아닌 가리키고 있는 실제 객체에 대해 기능을 사용
}

//포인터는 리모컨, 객체는 로봇
//리모컨의 기능 수는 로봇의 기능 수보다 작거나 같아야 함

// 이런식으로 어느 포인터(리모컨)을 사용하느냐에 따라 기능이 오버라이딩되는데, 이건 포인터의 자료형에 따라 함수가 달라지는 것이기 떄문에 문제가 됨
    // -> virtual 사용
    // 즉, 가리키는 객체의 타입에 따라 기능을 사용하려면 virtual 사용


// 결국 다형성은 포인터가 같음에도 가리키고 있는 객체에 따라 다른 결과를 내게 하는 것임