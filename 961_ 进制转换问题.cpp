#include <iostream>

using namespace std;

class Stack{
    private:
    int* top;
    int* bottom;
    const int maxsize;
    int* stack;
    public:
        Stack(int size): maxsize(size){
            stack = new int[maxsize];
            top = bottom = stack;
        }
        int push(int val){
            if(top-bottom == maxsize) return -1;
            *top=val;
            top++;
            return 1;
        }
        int pop(){
            if(top-bottom == 0) return -1;
            return *(--top);
        }
        bool is_empty(){
          return top-bottom==0 ? true : false;
        }
};
int main(){
    Stack a(32);
    int num;
    cin >> num;
    while(num){
       a.push(num%2);
       num/=2;
    }
    while(!a.is_empty())
      cout << a.pop();
    return 0;
}