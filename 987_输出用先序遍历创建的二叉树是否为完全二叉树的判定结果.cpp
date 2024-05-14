#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Node{
    public:
        char data;
        Node* lchild;
        Node* rchild;
        Node(char data) : data(data), lchild(NULL), rchild(NULL){}
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
        void Destory(Node* root){
            if(root == NULL) return;
            Destory(root->lchild);
            Destory(root->rchild);
            delete root;
        }
    public:
        Binary_Tree(string str){
            int index = 0;
            root = Create(str, index);
        }
        bool is_completetree(){
            queue<Node*> a;
            a.push(root);
            bool is_null = false;

            while(!a.empty()){
                if(a.front() == NULL)
                    is_null = true;
                else{
                    if(is_null)
                        return false;
                    a.push(a.front()->lchild);
                    a.push(a.front()->rchild);
                }
                
                a.pop();
            }
            return true;
        }
        ~Binary_Tree(){
            Destory(root);
        }
};
int main(){
    string str;
    cin >> str;
    Binary_Tree a(str);
    if(a.is_completetree())
        cout << 'Y';
    else
        cout << 'N';
    return 0;
}
