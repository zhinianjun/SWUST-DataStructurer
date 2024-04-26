#include <iostream>

using namespace std;

class Stack{
    private:
    const int maxsize;
    int *base;
    int *top;

    public:

    Stack(int size) : maxsize(size){
        base = new int[this->maxsize];
        if(base == NULL) return;
        top = base;
    }

    bool push(int data){
        if(top - base == maxsize) return -1;
        *top = data;
        top++;
        return 1;
    }

    bool pop(){
        if(top -  base == 0) return -1;
        top--;
        return 1;
    }

    int get_top(){
        if(top == base) return -1;
        int *p = top;
        return *(--p);
    }

    ~Stack(){
        delete[] base;
        base = nullptr;
        top = nullptr;
    }

};

int main(){
    Stack stack1(4);
    stack1.push(1);
    cout << "the top number is " << stack1.get_top() <<endl;
    stack1.push(2);
    cout << "the top number is " << stack1.get_top() <<endl;
    stack1.push(3);
    cout << "the top number is " << stack1.get_top() <<endl;
    stack1.push(4);
    cout << "the top number is " << stack1.get_top() <<endl;

    stack1.push(5);
    cout << "the top number is " << stack1.get_top() <<endl;

    stack1.pop();
    cout << "the top number is " << stack1.get_top() <<endl;


    return 0;
}