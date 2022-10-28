/*C 표준 라이브러리 사용*/

#include <cstdio> // .h를 빼고 c를 더하면 C 표준 라이브러리를 사용 가능
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    char str1[] = "Result";
    char str2[30];

    strcpy(str2, str1);
    printf("%s: %f \n", str1, sin(0.14));
    printf("%s: %f \n", str2, abs(-1.25));
    return 0;
}
