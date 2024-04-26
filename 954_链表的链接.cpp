#include <iostream>

using namespace std;

class Node{
    public:
        char data;
        Node* next;
        Node(int val) : data(val), next(nullptr){}
};

class List{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        List(){
            head = new Node(-1);
            tail = head;
            length = 0;
        }
        bool append(int val){
                Node* newnode = new Node(val);
                tail->next = newnode;
                tail = newnode;
                this->length++;
                return 1;
        }

       bool add(List& b){
            Node* temp = b.head->next;
            while(temp){
                Node* newnode =new Node(temp->data);
                this->tail->next = newnode;
                temp = temp->next;
                this->tail = newnode;
            }
            return 1;
       }

        void print(){
            Node* temp = head->next;
            while(temp)
            {
                cout << temp->data << ' ';
                temp = temp->next;
            }
                
        }
        ~List(){
            Node* temp = this->head;
            while(temp){
                Node*t = temp;
                temp = temp->next;
                delete t;
            } 
        }

};
int main()
{
    List a;
    int length;
    cin >> length;
    char val;
    for(int i = 0; i < length; i++)
    { 
        cin >> val;
        a.append(val);
    }
    // a.print();
    List b;
    cin >> length;
    for(int i = 0; i < length; i++)
    { 
        cin >> val;
        b.append(val);
    }
    // b.print();

    a.add(b);
    a.print();
    return 0;
} 

