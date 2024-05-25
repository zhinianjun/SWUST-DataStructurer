#include <iostream>
#include <climits>
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
        int height(Node* root){
            if(root == NULL)
                return 0;
            int left_height = height(root->lchild);
            int right_height = height(root->rchild);

            return 1 + max(left_height, right_height);
        }
        //ABC#E###D##   
        bool balance(Node* root){
            if(root == NULL)
                return true;
            if(!balance(root->lchild)) return false;
            if(!balance(root->rchild)) return false;
            int left = height(root->lchild);
            int right = height (root->rchild);
            if(abs(left - right) > 1)
                return false;
            return true;
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
    bool is_balance(){
        return balance(root);
    }

    ~Binary_Tree(){
        Destroy(root);
    }
    
};

int main(){
    string str;
    cin >> str;

    Binary_Tree a(str);
    if(a.is_balance())
        cout << "yes!";
    else
        cout << "no!";
    return 0;
}