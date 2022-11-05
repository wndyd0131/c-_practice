#include <iostream>
using namespace std;

class constObj{
    private:
    int num;
    public:
    constObj(int n): num(n){

    }
    constObj &AddNum(int n){
        num += n;
        return *this;
    }
    void ShowData() const{
        cout<<"num: "<<num<<endl;
    }
};

int main(){
    const constObj obj(7);
//    obj.AddNum(4); //const 멤버함수만 호출가능하여 실행 안 됨
    obj.ShowData();
    return 0;
}