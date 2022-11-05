/*상속의 필요성*/
//주석처리 해결//
    // Employee 클래스에 virtual ShowSalaryInfo()랑 GetPay()를 더함
//순수 가상 함수 (abstract) 
    // Employee는 단순 추상 클래스 역할이기 때문에 이를 추상 클래스로 만들어 줌
    // virtual ~~ = 0
#include <iostream>
#include <cstring>
using namespace std;

class Employee{
    private:
    char name[100];
    public:
    Employee(char *name){
        strcpy(this->name, name);
    }
    void ShowYourName() const{
        cout<<"name: "<<name<<endl;
    }
    // virtual void ShowSalaryInfo() const{
        
    // }
    // virtual int GetPay() const{
    //     return 0;
    // }
    // =>
    virtual void ShowSalaryInfo() const = 0; //순수 가상
    virtual int GetPay() const = 0; //순수 가상
    //이로써 Employee는 객체로서 생성되지 못하게 됨
};

// 데이터적 성격
class PermanentWorker: public Employee
{
    private:
    int salary;

    public:
    PermanentWorker(char name[], int money)
    : Employee(name), salary(money)
    {
    }
    int GetPay() const{
        return salary;
    }
    void ShowSalaryInfo() const{
        ShowYourName();
        cout<<"salary: "<<GetPay()<<endl<<endl;
    }
};

class TemporaryWorker:public Employee{
    private:
    int workTime;
    int payPerHour;
    public:
    TemporaryWorker(char *name, int pay):Employee(name), workTime(0), payPerHour(pay)
    {
    }
    void AddWorkTime(int time){
        workTime += time;
    }
    int GetPay() const{
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const{
        ShowYourName();
        cout<<"salary: "<<GetPay()<<endl<<endl;
    }
};

class SalesWorker: public PermanentWorker{
    private:
    int salesResult;
    double bonusRatio;
    public:
    SalesWorker(char *name, int money, double ratio):PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    {
    }
    void AddSalesResult(int value){
        salesResult += value;
    }
    int GetPay() const{
        return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio); //메서드 오버라이딩 때문에 굳이 PermanentWorker::GetPay()와 같이 이름을 지정해줌 
    }
    void ShowSalaryInfo() const{
        ShowYourName();
        cout<<"salary "<<GetPay()<<endl<<endl;
    }
};

// 기능적 성격 (컨트롤, 핸들러 클래스)
class EmployeeHandler{
    private:
    Employee *empList[50];
    int empNum;

    public:
    EmployeeHandler(): empNum(0){
        
    }
    void AddEmployee(Employee *emp){
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const{
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const{
        int sum = 0;
        for (int i = 0; i < empNum; i++){
            sum += empList[i]->GetPay();
        }
        cout<<"salary sum: "<<sum<<endl;
    }
    ~EmployeeHandler(){
        for(int i = 0; i < empNum; i++){
            delete empList[i];
        }
    }
};

int main(){
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();
    return 0;
}


// 위 프로그램은 전혀 문제 없지만
// 프로그램의 설계에 있어 중요한 것인
// 1) 프로그램의 유연성     2) 프로그램의 확장성 (컨트롤 클래스에 변화가 적다면 확장성이 좋은 것)
// 이 부족함


//EmployeeManager2.cpp는 EmployeeManager1.cpp를 잘 확장함
//하지만 다음과 같은 문제점이 존재함:
//PermanentWorker과 SalesWorker가 완전히 동일한 메서드인 ShowSalaryInfo()를 가짐에도, 둘 다 정의를 해주어야 함, 원인은 GetPay() 때문