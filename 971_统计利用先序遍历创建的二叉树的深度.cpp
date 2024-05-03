#include <iostream>
#include <string>

using namespace std;
class Node{
  public:
    char data;
    Node* lchild;
    Node* rchild;
    
    Node(int val):data(val){
      lchild = rchild = nullptr;
    }
};

class Binary_Tree{
  private:
    Node *root;
    int depth;
    
    void create(Node*& a, string str, int& index){
      if(str[index]=='#' || str[index]=='\0')
      {
        index++;
        return;
      }
      a = new Node(str[index]);
      index++;
      create(a->lchild, str, index);
      create(a->rchild, str, index);
    }

    int deep(Node* a){
        if(a==nullptr) return 0;
        int deep_left = deep(a->lchild);
        int deep_right = deep(a->rchild);
        return deep_left >= deep_right ? deep_left + 1: deep_right + 1;
    }

    void clear(Node* a){
      if(a == nullptr) return;
      Node* templ = a->lchild;
      Node* tempr = a->rchild;
      delete a;
      clear(templ);
      clear(tempr);
    }
  public:
    Binary_Tree(string str) : root(nullptr), depth(0){
      int index = 0;
      create(root, str, index);
      depth = deep(root);
    }
    int get_deep(){
      return this->depth;
    }
    ~Binary_Tree(){
      clear(root);
    }
};

int main(){
      string str;
      cin>>str;
      Binary_Tree a(str);
      cout << a.get_deep();

  return 0;
}