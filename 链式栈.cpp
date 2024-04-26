#include <iostream>

using namespace std;

class Node{
    private:
    int data;
    Node* next;

    public:
    Node(int val) : data(val), next(nullptr){}
    friend class Stack;
};

class Stack{
    private:
    int numbers;
    Node* base;
    Node* top;    

    public:
    Stack(){
       base = new Node(0);
       top = base;
    }

    bool push(int data){
        Node* newnode = new Node(data);
        if(newnode == nullptr)  return -1;
        newnode->next = top;
        top = newnode;
        return 1;
    }

    bool pop(){
        if(top==base) return -1;
        Node* p = top;
        top = top->next;
        delete p;
        return 1;
    }

    int get_top(){
       return this->top->data;
    }

    ~Stack(){
        while(top){
        Node *p = top;
        top = top->next;
        delete p;
       }
       top = nullptr;
       base = nullptr;
    }

};

int main(){
    Stack stack1;
    stack1.push(1);
    cout << "the top number is " << stack1.get_top() <<endl;
    stack1.push(2);
    cout << "the top number is " << stack1.get_top() <<endl;
    stack1.push(3);
    cout << "the top number is " << stack1.get_top() <<endl;
    stack1.push(4);
    cout << "the top number is " << stack1.get_top() <<endl;
    stack1.pop();
    cout << "the top number is " << stack1.get_top() <<endl;
    stack1.pop();
    cout << "the top number is " << stack1.get_top() <<endl;
    return 0;
}