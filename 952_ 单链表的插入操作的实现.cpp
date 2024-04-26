#include <iostream>

using namespace std;

class Node{
       
    public:
        int data;
        Node* next;
        friend class List;
        Node(int val) : data(val), next(nullptr){}
};

class List{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        List(){
            head = new Node(1);
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

        bool insert(int val, int pos){
            if(pos > length || (pos < 1 )){
                return false;
            }else{
                Node* temp = head;
                Node* newnode = new Node(val);
                for(int i = 0; i < pos - 1; i++) temp = temp->next;
                newnode->next = temp->next;
                temp->next = newnode;
                return true;
            }
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
    // a.print();
    int pos;
    cin >> pos >> val;

    if(a.insert(val, pos))
        a.print();
    else
        cout << "error!";
    return 0;
} 

