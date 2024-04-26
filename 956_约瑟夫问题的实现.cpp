#include <iostream>

using namespace std;

class Node{
    public:
        int data;
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
                tail->next = head;
                this->length++;
                return 1;
        }
    
    //4、8、2、7、3、10，9、1、6、5
        void josephus(int num){
            if (num <= 0 || length <= 1) {  
                // 非法输入或链表已经为空或只有一个节点  
                return;  
            }  
            Node* temp = head;
            while(this->length != 1){
                for(int i = 1; i <= num - 1; i++) 
                {
                    temp = temp->next;
                    if(temp==head) temp = head->next;
                }
                if(temp == this->tail){
                    Node* t = head->next;
                    head->next = head->next->next;
                    delete t;
                    length--;
                    continue;
                }else{
                    if(temp->next->next == head)    this->tail = temp;
                    Node* t = temp->next;
                    temp->next = t->next;
                    delete t;
                    length--;
                }
            }
        } 
        void print(){
            cout << head->next->data;
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
    for(int i = 0; i < length; i++)
    { 
        a.append(i+1);
    }

    int num;
    cin >> num;
    a.josephus(num);
    a.print();
    return 0;
} 

