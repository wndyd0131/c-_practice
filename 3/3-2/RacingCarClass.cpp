//클래스
#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST{
    enum{
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

//클래스
class Car{
    private: //접근제어
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

    public:
    void InitMembers(char *ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

void Car::InitMembers(char *ID, int fuel){
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

/*
......
*/

int main(){
    // ...
}



//접근제어 지시자2
//1) public
//2) protected
//3) private