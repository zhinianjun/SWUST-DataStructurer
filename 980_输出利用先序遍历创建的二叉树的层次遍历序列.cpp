#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Node{
    public:
    char data;
    Node* lchild;
    Node* rchild;
    Node(char val) : data(val), lchild(NULL), rchild(NULL){}
};

class Binary_Tree{
    private:
        Node* root;
        void creat(Node*& n, string str, int& index){
            if(str[index] == '#' || str[index] == '\0') {
                index++;
                return;
            }
            n = new Node(str[index]);
            index++;
            creat(n->lchild, str, index);
            creat(n->rchild, str, index);
        }
        void destroy(Node*& n){
            if(n==NULL) return;
            destroy(n->lchild);
            destroy(n->rchild);
            delete n;
        }
    public:
        Binary_Tree(string str) : root(NULL){
           int index = 0;
           creat(root, str, index);
        //    cout << root->data << endl;
        }

        void level_traversal(){
            queue<Node*> a;
            if(root != NULL)
                a.push(root);
            while(!a.empty()){
                if(a.front()->lchild != NULL)
                    a.push(a.front()->lchild);
                if(a.front()->rchild != NULL)
                    a.push(a.front()->rchild);
                cout << a.front()->data;
                a.pop();
            }
        }

        ~Binary_Tree(){
            destroy(root);
        }
};
int main(){
    string str;
    cin >> str;

    Binary_Tree a(str);
    a.level_traversal();
    return 0;
}