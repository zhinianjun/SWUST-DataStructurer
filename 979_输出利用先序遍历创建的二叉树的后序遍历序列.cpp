#include <iostream>
#include <string>

using namespace std;

class Node{
    public:
    char data;
    Node* lchild;
    Node* rchild;
    Node(char val) : data(val), lchild(NULL), rchild(NULL){}
};
class Binaty_Tree{
    private:
        Node* root;
        void create(Node*& root, string str, int& index){
            if(str[index] == '#')
            {
                index++;
                return;
            }
            root = new Node(str[index]);
            create(root->lchild, str, index);
            create(root->rchild, str, index);
        }
        void destroy(Node*& root){
            if(root) return;

            destroy(root->lchild);
            destroy(root->rchild);
            delete root;
            
        }
        void traverse(Node* root){
            if(root) return;
            traverse(root->lchild);
             cout << root->data;
            traverse(root->rchild);
        }
    public:
        Binaty_Tree(string str):root(NULL){
            int index = 0;
            create(root, str, index);
        }
        void traverse_back(){
            traverse(root);
        }
        ~Binaty_Tree(){
            destroy(root);
        }
};
int main(){
    string str;
    cin>>str;
    Binaty_Tree a(str);
    a.traverse_back();
    return 0;
}