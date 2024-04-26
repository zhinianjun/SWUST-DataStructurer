#include <iostream>

using namespace std;

class Node{
    private:
        int data;
        Node* next;

    public:
        Node(int val) : data(val), next(nullptr){}
        friend class Queue;

};

class Queue{
    private:
        Node* front;
        Node* rear;

    public:
        Queue(){
            this->front = new Node(0);
            this->rear = front;
        }

        bool push(int data){
            Node* newnode = new Node(data);
            if(newnode == nullptr) return -1;
            rear->next = newnode;
            rear = newnode;
            return 1;
        }

        int pop(){
            Node* p = this->front->next;
            int x = p->data;
            this->front->next = p->next;
            delete p;
            return x;
        }

        int length(){
            int nums = 0;
            Node* p = front;
            while(p != rear){
                nums++;
                p = p->next;
            }
            return nums;
        }

        void print(){
            Node* p = front->next;
            while(p){
                cout << p->data << ' ';
                p = p->next;
            }
            cout << endl;
        }

        ~Queue(){
            Node* p = front;
            while(p){
                Node* q = p;
                delete q;
                p = p->next;
            }
            this->front = nullptr;
            this->rear = nullptr;
        }
};
int main(){
    Queue queue1;
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);
    queue1.push(4);
    cout << "Now this queue have " << queue1.length() << " numbers" << endl;
    queue1.print();

    queue1.pop();
    queue1.pop();
    queue1.print();
    return 0;
}