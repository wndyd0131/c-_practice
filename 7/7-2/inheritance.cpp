/*상속*/
#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
    int age;
    char *name;
    
    public:
    Person(int myage, char *myname) : age(myage)
    {
        name = new char[strlen(myname) + 1];
        strcpy(name, myname);
    }
    void WhatYourName() const{
        cout<<"My name is "<<name<<endl;
    }
    void HowOldAreYou() const{
        cout<<"I'm "<<age<<" years old"<<endl;
    }
    ~Person(){
        delete []name;
    }
};

class UnivStudent: public Person //상속
{
    private:
    char *major;

    public:
    UnivStudent(char *myname, int myage, char *mymajor): Person(myage, myname) //super 생성자
    {
        major = new char[strlen(mymajor) + 1];
        strcpy(major, mymajor);
    }
    void WhoAreYou() const{
        WhatYourName();
        HowOldAreYou();
        cout<<"My major is "<<major<<endl<<endl;
    }
    ~UnivStudent(){
        delete []major;
    }
};

int main(){
    UnivStudent st1("Kim", 21, "Mathematics");
    st1.WhoAreYou();
    UnivStudent st2("Hong", 23, "Physics");
    st2.WhoAreYou();
    return 0;
}

//객체 생성 과정: 부모+자식의 메모리 할당 -> 자식클래스 생성자 -> 부모클래스 생성자 -> 객체 생성
//객체 소멸 과정: 자식 소멸 -> 부모 소멸 