/*멤버 이니셜라이저*/
// 멤버변수로 선언된 객체의 생성자를 호출
class Point{
    private:
    int x;
    int y;
    public:
    Point(const int &xpos, const int &ypos); // Rectangle의 멤버 이니셜라이저로 인해 생성자 call됨
};

class Rectangle{
    private:
    Point upLeft; // Composition (has)
    Point lowRight;
    public:
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) :upLeft(x1, y1), lowRight(x2, y2)
        {
            //
        }
};
//참고로, 객체뿐 아니라 일반 멤버변수들도 초기화할 수 있음 (이는 생성자에서 초기화하는가, 멤버이니셜라이저로 초기화하는가 결정할 수 있음)

//객체의 생성과정
//1) 메모리 할당
//2) 멤버 이니셜라이저
//3) 생성자 실행

//멤버이니셜라이저가 더 좋음
//이유: 1) 직관적임 2) 성능 (선언 후 바로 정의 형식으로 바이너리코드가 짜임) 3) 2의 사실로 인해 이니셜라이저로 const와 &참조자를 초기화 가능

/*디폴트 생성자*/
/*private 생성자*/ // 객체의 생성 제한을 하고 싶을 때 유용
/*소멸자*/ //destructor
    // 생성자는 객체 생성할 때 메모리를 할당, 소멸자에서는 이를 소멸시키는 코드를 씀 new <-> delete
    // ~클래스명