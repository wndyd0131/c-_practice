#include <iostream>
using namespace std;

class protectedTest{
    public:
    int num1;

    protected: // protected는 상속 클래스도 접근 가능
    int num2;

    private: // private는 상속 클래스도 접근 불가능
    int num3;
};

class protectedTestInher : protected protectedTest
{
    // protectedTest의 멤버 변수를 상속받되, protected보다 범위가 넓은 제어자에 대해 protected로 변환시킴
};

class protectedTestInher2{
//    int num = protectedTestInher::num1; // 상속받지 않은 체 protected에 접근하여 컴파일 에러
};