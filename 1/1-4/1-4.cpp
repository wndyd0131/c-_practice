/* 인라인 함수 */
//매크로 함수는 성능이 더 빨라지지만, 복잡한 함수를 정의하는 데에 한계가 있음
//인라인이란 전처리 과정에서 함수의 몸체부분이 함수호출 문장으로 대체되는 것 (예로, SQUARE(5)가 ((5)*(5))로 변하는 것)
//매크로 함수의 단점을 보완하기 위해 인라인 함수라는 게 C++에 도입됨, 그러나 여기서 인라인은 전처리기가 아닌 컴파일러에 의해 처리됨

#include <iostream>


// inline int SQUARE(int x){ //허나, 매크로 함수와 달리 자료형의 제한이 있다는 단점이 있음
//     return x*x;
// }

template <typename T> //그래서 template이라는 것을 사용
inline int SQUARE(T x){
    return x*x;
}

int main(){
    std::cout<<SQUARE(5)<<std::endl;
    std::cout<<SQUARE(12)<<std::endl;
}