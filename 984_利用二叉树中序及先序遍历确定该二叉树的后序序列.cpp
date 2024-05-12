#include <iostream>
#include <string>

using namespace std;

void Last_Sequence(string pre, string mid, string& last){
    string::const_iterator i = mid.begin();
    string L_tree, R_tree;

    while(1){
        if(*i == pre[0]) break;
        L_tree += *i;
        i++;
    }
    i++;
    for(;i != mid.end(); i++) R_tree += *i;
    // if(L_tree.length() == 1 || R_tree.length() == 1)
    // {
    //     last += L_tree;
    //     last += R_tree;
    //     return;
    // }
    if(!L_tree.empty())
    {
        string l = pre.substr(1, L_tree.length());
        // cout << l << endl;
        Last_Sequence(l,L_tree,last);
    }
        
    if(!R_tree.empty())
    {
        
        string r = pre.substr(mid.find(pre[0])+1, R_tree.length());
        // cout << r << endl;
        Last_Sequence(r, R_tree, last);
    }
        
    last += pre[0];
}
int main(){
    string Pre_str, Mid_str, Last_str;
    cin >> Mid_str >> Pre_str;

   Last_Sequence(Pre_str, Mid_str, Last_str);
   cout << Last_str;
    return 0;
}