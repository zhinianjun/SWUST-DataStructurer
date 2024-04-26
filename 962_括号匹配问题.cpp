#include <iostream>
#include <string>

using namespace std;

class Stack{
    private:
    char* top;
    char* bottom;
    const int maxsize;
    char* stack;
    public:
        Stack(int size): maxsize(size){
            stack = new char[maxsize];
            top = bottom = stack;
            *top='\0';
        }
        bool is_empty(){
            return top-bottom ? false : true;
        }
        char get_top(){
            if(top==bottom)
                return '\0';
            char* p = top;
            return *(--p);
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
        ~Stack(){
            delete[] stack;
        }
};
int main(){
    Stack a(50);
    string sign;
    cin >> sign;
    for(int i=0;i<int(sign.length());i++){
        
        switch(sign[i]){
            case '(':
                a.push(sign[i]);
            break;
            case '[':
                a.push(sign[i]);
            break;
            case ')':
                if(a.get_top() == '(')
                    a.pop();
                else
                    a.push(sign[i]);
            break;
            case ']':
                if(a.get_top() == '[')
                    a.pop();
                else
                    a.push(sign[i]);
            break;
        }
        // cout << a.get_top() << '\n';
    }
    if(a.is_empty())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}