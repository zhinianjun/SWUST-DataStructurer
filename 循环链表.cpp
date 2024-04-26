#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL){}
};

class List{
    private:
    Node* head;
    Node* tail;

    public:
    List(){
        this->head = new Node(0);
        this->tail = head;
    }

    int length(){
        int nums = 0;
        Node* p = head;
        while(p!=tail){
            nums++;
            p=p->next;
        }
        return nums;
    }
    bool append(int data){
        Node* newnode = new Node(data);
        if(newnode == nullptr) return -1;
        
        this->tail->next = newnode;
        newnode->next = head;
        this->tail = newnode;
        return 1;
    }

    bool insert(int index, int data){
        Node* newnode = new Node(data);
        Node* p = head;
        if(index <= 0 || index > this->length()) return -1;
        for(int i = 1; i <= index-1;i++) p = p->next;
        newnode->next = p->next;
        p->next = newnode;
        return 1;
    }

    int get_last_value(){
        return this->tail->data;
    }

    bool remove(int index){
        Node* p = head;
        if(index <= 0 || index > this->length()) return -1;
        for(int i = 1; i <= index-1; i++) p = p->next;

        if(index == this->length()){
            
            Node*q = p->next;
            this->tail = p;
            delete q;
            tail->next = head;
            return 1;
        }
        
        Node* q = p->next;
        p->next = p->next->next;
        delete q;

        return 1;
    }

    int get_firt_value(){
        return this->tail->next->next->data;
    }

    void print(){
        Node* p = head->next;
        while(p != head) 
        {
            cout << p->data << ' ';
            p = p->next;
        }
        cout << endl;
    }

    void merge(List &l){
        if(l.head==l.tail) return;
        Node*p = l.head;
        this->tail->next = p->next;
        delete p;
        this->tail = l.tail;
        this->tail->next = this->head;
        l.tail = NULL;
    }

    ~List(){
       //循环链表先断开首尾循环
       this->tail->next = NULL;
       Node* p = head;
       //然后使用单向链表的方法销毁内存
       while(p){
        Node* q = p;
        p=p->next;
        delete q;
       }
        this->head = NULL;
    }

};
int main(){
    List list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);
    list1.append(4);

    list1.print();

    cout << "the first number is " << list1.get_firt_value() <<endl;
    cout << "the last number is " << list1.get_last_value() <<endl;
    cout << "this list's length is " << list1.length() << endl;

    list1.insert(2, 55);
    list1.append(55);
    list1.print();

    list1.remove(2);
    list1.print();
    list1.remove(list1.length());
    list1.print();

    List list2;
    list2.append(5);
    list2.append(6);
    list2.append(7);
    list2.append(8);
    list1.merge(list2);
    list1.print();

    cout << "the first number is " << list1.get_firt_value() <<endl;
    cout << "the last number is " << list1.get_last_value() <<endl;
    cout << "this list's length is " << list1.length() << endl;

    return 0;
}