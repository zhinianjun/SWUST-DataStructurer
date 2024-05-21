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
      if(n>1)
        root = new Node(a[0]);
      
      for(int i = 1; i < n; i++){
        Node* temp = root;
      
        while((a[i] > temp->data && temp->rchild != NULL) || (a[i] < temp->data && temp->lchild != NULL)){
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
      while(temp!=NULL){
        times++;
        //cout << temp->data << endl;
        if(temp->data == val)
          return times;
        else if(val > temp->data)
          temp = temp->rchild;
        else
          temp = temp->lchild;
      }
      return -1;
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
  
  int num;
  cin >> num;
  cout << find_tree.find(num);
  
  delete[] a;
  return 0;
}