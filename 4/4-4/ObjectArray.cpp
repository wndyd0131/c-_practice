/*객체의 배열*/
class objectArrayTest{

};

int main(){
    objectArrayTest arr[10]; // 정적 할당
    objectArrayTest *ptr = new objectArrayTest[10]; // 동적 할당
    return 0;
}
// 생성자를 일일이 초기화해줘야 함