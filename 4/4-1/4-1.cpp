/*정보 은닉*/
/* const함수 */ // const 함수는 멤버변수를 변경시키는 코드에 대해 컴파일 에러를 발생시킴, 프로그래머의 실수를 줄이는 용도
    // const함수 내에서는 const 함수만 call 가능
#include <iostream>
using namespace std;

class constTest{
    private:
    int num;
    
    public:
    void InitNum(int n){
        num = n;
    }
    int GetNum(){
        return num;
    }
    void ShowNum() const{
        cout<<GetNum()<<endl; // GetNum()이 const함수가 아니라 오류
    }
}