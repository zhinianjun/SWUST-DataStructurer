#include <iostream>

using namespace std;

class Node{
    public:
        char data;
        Node* next;
        Node(char val) : data(val), next(nullptr){}
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
        void reverse(){
            Node* curr = head->next;
            Node* pre = nullptr;
            while (curr)
            {
                Node* temp = curr->next;
                curr->next=pre;
                pre = curr;
                curr = temp;
            }
            head->next = pre;
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
    a.reverse();
    a.print();
    return 0;
} 

