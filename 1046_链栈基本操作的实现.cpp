#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr){

        }
};

class List_Stack{
    private:
        Node* top;
        Node* bottom;
    public:
        List_Stack() : top(nullptr), bottom(nullptr){
            bottom = new Node(-1);
            top = bottom;
        }
        void push(int data){
            Node* newnode = new Node(data);
            top->next = newnode;
            top = newnode;
        }
        int pop(){
            if(bottom == top) return -1;
            Node* temp = bottom;
            while(temp->next!=top) temp=temp->next;
            int val = top->data;
            delete top;
            top = temp;
            return val;
        }
        ~List_Stack(){
            while(bottom->next){
                Node* temp = bottom;
                delete temp;
                bottom = bottom->next;
            }
        }
};

int main(){
    int num;
    cin >> num;
    List_Stack a;
    for(int i = 0;i<num;i++)
    {
        int data;
        cin>>data;
        a.push(data);
    }
  
    cin >> num;
    for(int i = 0; i<num; i++)
        a.pop();

    cout << a.pop();
    return 0;
}