#include <iostream>
#include <stack>
#include <string>

using namespace std;

int prior(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}

bool is_Oprator(char ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string middletolast(string str){
    stack<char> s;
    string::const_iterator start = str.begin();
    string res;
    for(; start != str.end(); start++){
        // cout << *start << endl;
        if(isalpha(*start))
        {
            res += *start;
            continue;
        } 
        if(is_Oprator(*start)){
            while(!s.empty() && prior(s.top()) >= prior(*start))
            {
                res += s.top();
                s.pop();
            }
            s.push(*start);
        }else if(*start == '(') s.push(*start);
        else if (*start == ')') 
        {
            while(!s.empty() && s.top() != '('){
                res += s.top();
                s.pop();
            }
            s.pop();
        } 
    }
         while(!s.empty())
        {
            res += s.top();
            s.pop();
        } 
    return res;
}

int main(){
    string str, res;
    cin >> str;
    res = middletolast(str);
    cout << res;
    return 0;
}