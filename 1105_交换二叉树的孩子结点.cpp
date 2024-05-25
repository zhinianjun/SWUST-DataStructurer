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
        void swapHelper(Node* root){
            if(root==NULL)
              return;
            Node* temp = root->lchild;
            root->lchild = root->rchild;
            root->rchild = temp;
            swapHelper(root->lchild);
            swapHelper(root->rchild);
        }
        void traverse_middle(Node* root){
          if(root==NULL)
            return;
          traverse_middle(root->lchild);
          cout << root->data;
          traverse_middle(root->rchild);
        }
        void traverse_first(Node* root){
          if(root==NULL)
            return;
          cout << root->data;
          traverse_first(root->lchild);
          traverse_first(root->rchild);
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
        void swap(){
            swapHelper(root);
        }
        void traverse(){
            traverse_middle(root);
            cout << endl;
            traverse_first(root);
        }
          ~Binary_Tree(){
            Destroy(root);    
        }
};
int main(){
    string str;
    cin >> str;
    Binary_Tree a(str);
    a.swap();
    a.traverse();
    return 0;
}