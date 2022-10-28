/* 이름공간(namespace) */
//여러 프로젝트를 합칠 때 이름충돌이 발생할 가능성이 있는데, 이에 대한 해결책
//결론적으로, ::는 범위지정 연산자라고 불리는 namespace 지정용 연산자
#include <iostream>
using std::cout; //using은 namespace에 존재하는 함수 또는 변수를 더 이상 namespace 명시 없이 사용 가능하도록 함 (전역 변수일 시 전 범위 / 지역 변수일 시 그 내에서 발휘됨)
using std::cin;
using std::endl;
using namespace std; //namespace std와 연관되는 모든 변,함수에 대해 using함

int val = 20;

void valTest(){
    int val = 3;
    val += 3; // 지역변수 6
    ::val += 3; // 전역변수 23
}

// 이름공간 별칭 지정
namespace AAA{
    namespace BBB{
        namespace CCC{
            int num1;
            int num2;
        }
    }
}
namespace ABC=AAA::BBB::CCC; //복잡함 문제 해결 AAA::BBB::CCC::num1 -> ABC::num1

//정의
namespace BestComImpl{
    void SimpleFunc();
    void PrettyFunc();
}
namespace ProgComImpl{
    void SimpleFunc();
}

namespace Parent{ //이름공간 중첩 (같은 변수가 서로 다른 이름공간에 있게 하기)
    int num=2;
    namespace SubOne{
        int num=3;
    }
    namespace SubTwo{
        int num=4;
    }
}

//선언
void BestComImpl::SimpleFunc(){
    std::cout<<"BestCom이 정의한 함수"<<std::endl;
    PrettyFunc(); //같은 이름공간에 존재하는 함수를 선언할 때에는 이름공간을 명시할 필요 없음
}
void ProgComImpl::SimpleFunc(){
    std::cout<<"ProgCom이 정의한 함수"<<std::endl;   
}

int main(){
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    std::cout<<Parent::SubOne::num<<std::endl;
    cout<<Parent::SubTwo::num<<std::endl; //using 사용
    return 0;
}

void BestComImpl::PrettyFunc(){
    std::cout<<"So Pretty!"<<std::endl;
}