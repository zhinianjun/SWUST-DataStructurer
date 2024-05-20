#include <iostream>

using namespace std;

class Node{
  public:
    int data;
    Node* lchild;
    Node* rchild;
    Node(int data) : data(data), lchild(NULL), rchild(NULL){}
};
class Binary_Tree{
  private:
    Node* root;
    
    void Destroy(Node* root){
      if(root == NULL) return;
      Destroy(root->lchild);
      Destroy(root->rchild);
      delete root;
    }
  public:
    Binary_Tree(int a[], int n) : root(NULL){
      if(n>0)
        root = new Node(a[0]);
      
      for(int i = 1; i < n; i++){
        Node* temp = root;
      
        while(temp->lchild != NULL && temp->rchild != NULL){
          if(a[i] > temp->data) temp = temp->rchild;
          else if(a[i] < temp->data) temp = temp->lchild;
        }
          Node* t = new Node(a[i]);
          if(a[i] > temp->data) temp->rchild = t;
          else if(a[i] < temp->data) temp->lchild = t;
      }

    }
    int find(int val){
      int times = 0;
      Node* temp = root;
      if(root->data == val) return 1;
      while(temp->data != val){
        times++;
        if(temp->lchild == NULL && temp->rchild == NULL && temp->data != val)
          return -1;
        if(val > temp->data) temp = temp->rchild;
        else if(val < temp->data) temp = temp->lchild;
      }
    }
    ~Binary_Tree(){
      Destroy(root);
    }
};
int main(){
  int n;
  cin >> n;
  int* a = new int[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  Binary_Tree find_tree(a, n);
  delete[] a;
  return 0;
}