//아래의 오버로딩은 문제가 있다. 왜냐하면, 첫번째 SimpleFunc를 비워도 되는 상황인데, 비우게 될 시 첫번째 함수를 콜해야 할지 두번쨰 함수를 콜해야 할지 알 수 없기 때문
int SimpleFunc(int a=10){
    return a + 1;
}

int SimpleFunc(){
    return 10;
}