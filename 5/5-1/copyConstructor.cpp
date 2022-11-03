#include <iostream>
using namespace std;

class copyConstructor{
    private:
    int num1;
    int num2;

    public:
    copyConstructor(int n1, int n2):num1(n1), num2(n2)
    {
        // 일반적인 생성자
    };
    copyConstructor(const copyConstructor &copy):num1(copy.num1), num2(copy.num2) //원래는 &연산자를 뺄 시 무한루프가 발생한다고 함
    {
        // 복사 생성자
    }
    // explicit copyConstructor(const copyConstructor &copy):num1(copy.num1), num2(copy.num2)
    // {
    //     // explicit: copyConstructor cl2 = cl1는  copyConstructor cl2(cl1)으로 변환되는데, 이런 묵시적 변환을 사용하지 못하게 하여 반드시 cl2(cl1) 형식을 지키도록 함
    //     // 이외에도, 묵시적 변환이 일어나는 경우를 막기 위해서 explicit을 사용
    // }
};

int main(){
    copyConstructor cl1(15, 30);
    copyConstructor cl2(cl1); //복사
}

//default 복사 생성자: 위와 같이 코딩하지 않아도, 복사 생성자가 묵시적으로 정의가 되어 있음

// 얕은 복사: 디폴트 복사 생성자 또는 위에 정의한 복사 생성자는 객체 자체를 복사해서 참조값들이 모두 같음
// 깊은 복사: 참조하는 대상까지 다른 주소로 복사하여 참조함

// 복사 생성자의 호출 시점
// 1) 기존의 객체에 새로운 객체를 초기화할 때
// 2) call-by-value 함수에 객체를 인자로 전달할 때
// 3) 참조형이 아닌 객체를 반환할 때