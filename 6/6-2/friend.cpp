/*friend*/
// private 멤버에 직접 접근 가능
#include <iostream>
#include <cstring>
using namespace std;

class Boy{
    private:
    int height;
    friend class Girl; // Girl을 friend로 두어, Girl이 Boy의 private에 접근 가능
    public:
    Boy(int len): height(len)
    {
    }
    friend void Girl::ShowYourFriendInfo(Boy&); // friend 함수
};

class Girl{
    private:
    char phNum[20];
    public:
    Girl(char *num){
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(Boy &frn){
        cout<<"His height: "<<frn.height<<endl;
    }
};

int main(){
    Boy ben(175);
    Girl bell("01012345678");
    bell.ShowYourFriendInfo(ben);
}