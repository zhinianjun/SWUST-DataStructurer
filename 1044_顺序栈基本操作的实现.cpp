#include <iostream>

using namespace std;

class Stack{
    private:
      int* stack;
      int* top;
      int* bottom;
      const int maxsize;
    public:
      Stack(int size):maxsize(size){
          top = bottom = nullptr;
          stack = new int[maxsize];
          top = bottom = stack;
      }
      bool is_empty(){
        return top == bottom ? true : false;
      }
      void push(int data){
        if(top-bottom == maxsize) return;
        *top = data;
        top++;
      }
      int pop(){
          if(this->is_empty()) return -1;
          top--;
          return *top;
      }
      ~Stack(){
        delete[] stack;
      }
};
int main(){
  int num;
  cin >> num;
  Stack a(num);
  for(int i = 0;i<num;i++)
  {
    int data;
    cin>>data;
    a.push(data);
  }
  
  cin >> num;
  for(int i = 0; i<num; i++)
    a.pop();

  cout << a.pop();
  return 0;
}