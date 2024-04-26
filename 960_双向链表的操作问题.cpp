#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* pre;
        Node(int val) : data(val), next(nullptr), pre(nullptr){}
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
        //10
        //2 4 6 3 5 8 10 21 12 9ss
        bool append(int val){
                Node* newnode = new Node(val);
                Node* temp = head->next;
                while(temp){
                    if(newnode->data<=temp->data){
                        newnode->next = temp;
                        newnode->pre = temp->pre;
                        temp->pre->next = newnode;
                        temp->pre = newnode;
                        return 1;
                    }
                    temp=temp->next;
                }
                this->tail->next = newnode;
                newnode->pre=this->tail;
                this->tail = newnode;
                // print();
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
    int val;
    for(int i = 0; i < length; i++)
    { 
        cin >> val;
        a.append(val);
    }
    a.print();
    return 0;
} 

