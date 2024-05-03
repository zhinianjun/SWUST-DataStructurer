#include <iostream>
#include <cctype>
#include <string>
#include <stack>

using namespace std;

int caculate(char op, int val_1, int val_2){
    switch (op)
    {
    case '+':
        return val_1 + val_2;
        break;
    case '-':
        return val_1 - val_2;
        break;
    case '*':
        return val_1 * val_2;
        break;
    case '/':
        if(val_2 != 0)
            return val_1 / val_2;
        break;
    default:
        return 0;
        break;
    }
    return 0;
}

bool is_Oprator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int Lastfix(string str){
    stack<int> s;
    string::const_iterator start = str.begin();
    for(;start != str.end(); start++){
        //  cout << *start << endl;
        if(isdigit(*start))
            s.push(*start - '0');
        else if(is_Oprator(*start))
        {
            int val_2 = s.top();
            s.pop();
            int val_1 = s.top();
            s.pop();
            
            int res = caculate(*start, val_1, val_2);
            // cout << val_1 << ' '<< *start << ' ' << val_2 << ' ' << '=' << res << endl;
            s.push(res);
        }
    }
    if(!s.empty()){
        return s.top();
    }
        return 0;
}

int main(){
    string str;
    char ch;
    cin >> ch;
    while(ch != '#'){
        str+=ch;
        cin >> ch;
    }
    int res = Lastfix(str);
    cout << res;
    return 0;
}