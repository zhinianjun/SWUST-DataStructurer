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
    int numbers;
    Node* head;

    public:
    List(){
        this->head = new Node(0);
        this->numbers = 0;
    }
    
    //在列表末尾插入一个节点
    bool append(int data){
        Node* newnode = new Node(data);
        Node *p = head;
        if(newnode == NULL) return 0;

        while(p->next) p = p->next;
        p->next = newnode;
        this->numbers++;
        return 1;
    }

    bool is_empty(){
        if(head->next != NULL) return 0;
        return 1;
    }

    int length(){
        Node *p = head;
        int num =0;

        while (p->next)
        {
            p = p ->next;
            num++;
        }
        return num;
        
    }
    void print(){
        Node* p = head;
        while(p){
            if(p == head){
                p = p->next;
                continue;
            }
            cout << p->data << ' ';
            p = p->next;
        }
        cout << endl;
    }

    //获取第indenx个元素的值
    int get_value(int index){
        Node* p = head;
        if(index <= 0 || index >= this->length()) return -1; 
        for(int i = 1; i <= index; i++){
            p = p->next;
        }
        return p->data;
    }

    //在第index个元素,前驱插入节点
    bool insert(int index, int data){
        Node* p = head;
        Node* newnode = new Node(data);
        if(index <= 0 || index >= this->length()) return 0; 
        for(int i = 1; i <= index - 1; i++) p=p->next;
        newnode->next = p->next;
        p->next = newnode;
        numbers++;
        return 1;
    }

    //删除第index处的节点
    bool remove(int index){
        Node *p = head;
        if(index <= 0 || index >= this->length()) return 0; 
        for(int i = 1; i <= index - 1; i++) p=p->next;
        Node *q = p ->next;
        p->next = p->next->next;
        delete q;
        return 1;
    }

    int found_value(int data){
        Node* p = head;
        int index = 1;
        while(p){
            if(p==head){
                p=p->next;
                continue;
            }
            if(p->data == data){
                return index;
            }
            index++;
            p=p->next;
        }
        return -1;

    }
    Node* found_addr(int data){
         Node* p = head;
        while(p){
            if(p==head){
                p=p->next;
                continue;
            }
            if(p->data == data){
                return p;
            }
            p=p->next;
        }
        return NULL;
    }

    void clear(){
        Node *p = head;
        while(p->next){
            Node *q = p;
            p=p->next;
            delete q;   
        }
        delete p;
        head->next = NULL;
    }

    ~List(){
        Node* p = head;
        while(p){
            Node* q = p;
            p = p->next;
            delete q;
        }
    }

};

int main(){
    
    List list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);
    list1.append(4);

    list1.print();

    if(list1.is_empty()) cout << "empty" << endl;
    else cout << "Not empty" << endl;

    cout << "This list's length:" << list1.length() << endl;

    cout << "2th number is:" << list1.get_value(2) << endl;
    cout << "5th number is:" << list1.get_value(5) << endl;

    list1.insert(2, 55);
    list1.print();

    list1.remove(2);
    list1.print();

    cout << list1.found_value(2) << endl;
    cout << list1.found_value(4) << endl;

    cout << list1.found_addr(2) << endl;
    cout << list1.found_addr(4) << endl;

    list1.clear();
    if(list1.is_empty()) cout << "empty" << endl;
    else cout << "Not empty" << endl;

    cout << "This list's length:" << list1.length() << endl;

    return 0;
}