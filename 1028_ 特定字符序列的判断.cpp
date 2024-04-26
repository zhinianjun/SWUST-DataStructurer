#include <iostream>
#include <string>

using namespace std;

int main(){
  string str;
  cin >> str;
  string::const_iterator start = str.begin();
  string::const_iterator rear = str.end() - 2;
  //cout << *start << ' ' << *rear << endl;
  while(*rear != '@'){
    if(*rear != *start){
      cout << "no!";
      return 0;
    }
    start++;
    rear--;
  }
  cout << "yes!";
  return 0;
}