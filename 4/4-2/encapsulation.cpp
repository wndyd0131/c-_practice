/* 캡슐화 */
// 여러 기능을 한 군데에 모으는 것
    // 기능의 순서 고정에도 영향을 미침
    // 프로그래머의 경험이 크게 작용하는 부분, 캡슐화를 잘 하는 것은 어려움
    // 캡슐화를 할 때 정보은닉을 시킴
#include <iostream>
using namespace std;

class SinivelCap{
    public:
    void Take() const {
        cout<<"콧물이 싹~ 납니다."<<endl;
    };
};

class SneezeCap{
    public:
    void Take() const{
        cout<<"재채기가 멎습니다."<<endl;
    };
};

class SnuffleCap{
    public:
    void Take() const{
        cout<<"코가 뻥 뚫립니다."<<endl;
    };
};

class CONTAC600{
    private:
    SinivelCap sin;
    SneezeCap sne;
    SnuffleCap snu;

    public: // 약의 복용 순서를 고려하지 않아도 됨
    void Take() const{
        sin.Take();
        sne.Take();
        snu.Take();
    }
};

class ColdPatient{
    public:
    void TakeCONTAC600(const CONTAC600 &cap) const { // 한 가지 행위로 여러 효과를 봄
        cap.Take();
    }
};

int main(){
    CONTAC600 cap;
    ColdPatient sufferer;
    sufferer.TakeCONTAC600(cap);
    return 0;
}