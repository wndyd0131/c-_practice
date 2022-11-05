#include <iostream>
#include <cstring>
using namespace std;

class Gun{
    private:
    int bullet;
    public:
    Gun(int bnum):bullet(bnum){}
    void Shot(){
        cout<<"BBANG!"<<endl;
        bullet--;
    }
};

class Police{
    private:
    int handcuffs;
    Gun *pistol; //Gun 객체 참조
    public:
    Police(int bnum, int bcuff):handcuffs(bcuff){
        if(bnum > 0)
        pistol = new Gun(bnum);
        else
        pistol = NULL;
    }
    void PutHandcuff(){
        cout<<"SNAP!"<<endl;
        handcuffs--;
    }
    void Shot(){
        if(pistol==NULL)
        cout<<"Hut BBANG!"<<endl;
        else
        pistol->Shot();
    }
    ~Police(){
        if(pistol!=NULL)
        delete pistol;
    }
};

int main(){
    Police pman1(5, 3);
    pman1.Shot();
    pman1.PutHandcuff();

    Police pman2(0, 3);
    pman2.Shot();
    pman2.PutHandcuff();
    return 0;
}

//Has-A-Inheritance.cpp에 비해 이 코드가 훨씬 나음.
// 1) 경찰이 권총을 소유하고 있음이 표현됨 2) 경찰이 다른 무기를 갖게 될 때 다른 무기 클래스를 만들어서 붙여주기만 하면 됨