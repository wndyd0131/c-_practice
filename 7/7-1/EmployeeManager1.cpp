/*상속*/
#include <iostream>
#include <cstring>
using namespace std;

// 데이터적 성격
class PermanentWorker{
    private:
    char name[100];
    int salary;

    public:
    PermanentWorker(char name[], int money)
    : salary(money){
        strcpy(this->name, name);
    }
    int GetPay() const{
        return salary;
    }
    void ShowSalaryInfo() const{
        cout<<"name: "<<name<<endl;
        cout<<"salary: "<<GetPay()<<endl<<endl;
    }
};

// 기능적 성격 (컨트롤, 핸들러 클래스)
class EmployeeHandler{
    private:
    PermanentWorker *empList[50];
    int empNum;

    public:
    EmployeeHandler(): empNum(0){
        
    }
    void AddEmployee(PermanentWorker *emp){
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
// 1) 프로그램의 유연성     2) 프로그램의 확장성
// 이 부족함