#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
        char data;
        Node* lchild;
        Node* rchild;
        Node(int data) : data(data), lchild(NULL), rchild(NULL){}
};

class Binary_Tree{
    private:
        Node* root;
        Node* Create(string str, int& index){
            if(str[index] == '#' || str[index] == '\0')
            {
                index++;
                return NULL;
            }
            Node* temp = new Node(str[index]);
            index++;
            temp->lchild = Create(str, index);
            temp->rchild = Create(str, index);
            return temp;
        }
        Node* find(Node* root, char data){
            if(root == NULL)
                return NULL;
            if(root->data == data)
                return root;
            Node* temp = find(root->lchild, data);
            if(temp != NULL)
                return temp;
            return find(root->rchild, data);
        }
        void Destroy(Node* root){
            if(root == NULL) return;
            Destroy(root->lchild);
            Destroy(root->rchild);
            delete root;
        }
    public:
        Binary_Tree(string str){
            int index = 0;
            root = Create(str, index);
        }
        int degree(char data){
            int deg = 0;
            Node* temp = find(root, data);
            
            if(temp==NULL){
                return 0;
            }
            deg = (temp->lchild != NULL) + (temp->rchild != NULL);
            return deg;
        }
        ~Binary_Tree(){
            Destroy(root);    
        }
};
int main(){
    string str;
    cin >> str;
    Binary_Tree a(str);
    char ch;
    cin >> ch;
    cout << a.degree(ch);
    return 0;
}