/* 프로젝트: 계좌 개설, 입금, 출금, 출력 기능 만들기 */
#include <iostream>
using namespace std;

typedef struct {
    int id;
    char name[20];
    int balance;
} Account;

Account arr[100];
int accnum = 0;

Account createAccount(){
    Account ac;
    cout<<"[계좌개설]"<<endl;
    cout<<"ID: ";
    cin>>ac.id;
    cout<<"이름: ";
    cin>>ac.name;
    cout<<"입금액: ";
    cin>>ac.balance;
    return ac;
}

void deposit(){
    int id;
    int money;
    cout<<"[입  금]"<<endl;
    cout<<"계좌ID: ";
    cin>>id;
    cout<<"입금액: ";
    cin>>money;
    for(int i = 0; i < accnum; i++){
        if(arr[i].id == id){
            arr[i].balance += money;
            break;
        }
        if(i == accnum - 1){
            cout<<"해당하는 계좌ID가 없습니다."<<endl;
        }
    }
}

void withdraw(){
    int id;
    int money;
}

void printAccounts(){
    for(int i = 0; i < accnum; i++){
        cout<<"---------"<<endl;
        cout<<"계좌 ID: "<<arr[i].id<<endl;
        cout<<"이름: "<<arr[i].name<<endl;
        cout<<"잔액: "<<arr[i].balance<<endl;
        cout<<"---------"<<endl;
    }
}

int main(){
    int choice;
    Account new_ac;
    while(1){
        cout<<"-----Menu------"<<endl;
        cout<<"1. 계좌개설"<<endl;
        cout<<"2. 입금"<<endl;
        cout<<"3. 출금"<<endl;
        cout<<"4. 계좌정보 전체 출력"<<endl;
        cout<<"5. 프로그램 종료"<<endl;
        cout<<"선택: ";
        cin>>choice;
        switch(choice){
            case 1:
            new_ac = createAccount();
            arr[accnum] = new_ac;
            if(accnum < 100) {
                accnum++;
                cout<<"계좌가 생성되었습니다. ("<<accnum<<"/100)"<<endl;
            }
            else cout<<"더 이상 계좌를 만들 수 없습니다. (100/100)"<<endl; 
            break;
            case 2:
            deposit();
            break;
            case 3:
            withdraw();
            break;
            case 4:
            printAccounts();
            break;
            case 5:
            return -1;
            default:
            break;
        }
    }
    Account ac = createAccount();
}