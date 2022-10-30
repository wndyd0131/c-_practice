/*생성자*/
// 오버로딩 가능, 매개변수 디폴트값 설정 가능
#include <iostream>
using namespace std;

class constructorTest{
    private:
    int num;
    int x;
    int y;
    public:
    constructorTest(int n){
        num = n;
    }
    constructorTest(int x, int y){
        x = x;
        y = y;
    }
    // constructorTest(int x, int y=0)
    // int GetNum() const{
    //     return num;
    // }
};

int main(){
    constructorTest cst(20); //전역, 지역변수
    constructorTest *ptr = new constructorTest(5); //동적 할당
}