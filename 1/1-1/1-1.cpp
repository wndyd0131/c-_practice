/* 압츌력 */
#include <iostream> //입출력 관련 헤더
int main(){
    //정수 입출력
    int var1;
    std::cout<<"숫자를 입력하시오"<<std::endl; //출력 + 개행
    std::cin>>var1; //입력 (데이터 타입에 따른 입력을 알아서 해줌)
    std::cout<<"val1 = "<<var1<<std::endl;

    //문자열 입출력
    char str[100];
    std::cout<<"문자열을 입력하시오"<<std::endl;
    std::cin>>str;
    std::cout<<"str = "<<str<<std::endl;
    /* C와 달리, C++에서는 지역변수의 선언 위치가 상관없음 */

    //여러 입력
    int var2, var3;
    std::cout<<"숫자 두 개를 입력하시오"<<std::endl;
    std::cin>>var2>>var3; //입력은 탭, 공백, 개행에 의해 나눠짐
    std::cout<<"var2 = "<<var2<<" var3 = "<<var3<<std::endl;
    return 0;
}
