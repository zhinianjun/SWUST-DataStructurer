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

        void create(Node*& a, string str, int& index){
            if(str[index] == '#' || str[index] == '\0')
            {
                index++;
                return;
            }
            a = new Node(str[index]);
            index++;
            create(a->lchild, str, index);
            create(a->rchild, str, index);
        }
        void destroy(Node*& a){
            if(a==NULL) return;

            destroy(a->lchild);
            destroy(a->rchild);
            delete a;
            
        }
        void traverse(Node* a){
            if(a==NULL) return;
            traverse(a->lchild);
            traverse(a->rchild);
            cout << a->data;
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