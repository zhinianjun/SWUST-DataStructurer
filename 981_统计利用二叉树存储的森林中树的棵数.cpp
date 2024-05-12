#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
        char data;
        Node* lchild;
        Node* rchild;
    Node(int val) : data(val), lchild(NULL), rchild(NULL){}
};

class Binary_Tree{
    private:
        Node* root;
        Node* Create(string str, int& index){
            if(str[index] == '#' || str[index] == '\0'){
                index++;
                return NULL;
            }
            Node* temp = new Node(str[index]);
            index++;
            temp->lchild = Create(str, index);
            temp->rchild = Create(str, index);
            return temp;
        }

        void Destroy(Node* n){
            if(n == NULL) return;
            Destroy(n->lchild);
            Destroy(n->rchild);
            delete n;
        }
    public:
    Binary_Tree(string str){
        int index = 0;
        root = Create(str, index);
        // cout << root->data << endl;
    }
    int calc_number(){
        if(root == NULL) return 0;
        int num = 1;
        Node* temp = root;
        while(temp)
        {
            if(temp->rchild != NULL) num++;
            temp = temp->rchild;
        }
        return num;
    }

    ~Binary_Tree(){
        Destroy(root);
    }
    
};


int main(){
    string str;
    cin >> str;

    Binary_Tree a(str);
    cout << a.calc_number();   
    return 0;
}