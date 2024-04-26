#include <iostream>

using namespace std;

int main(){
  int len;
  cin >> len;
  int* a = new int[len];
  for(int i = 0;i < len;i++){
    cin >> a[i];
  }
  int num;
  cin >> num;
  int times = 0;
  for(int i = 0; i < len;i++)
    if(a[i] == num)
      times++;
  if(times == len){
    cout << -1;
    return 0;
  }
  //1 2 3 4
  for(int t = 0; t<times;t++){
    for(int i = 0; i < len;i++){
      if(a[i]==num){
        len--;
        for(int j=i;j<len;j++)
          a[j] = a[j+1];
        break;
      }
      if(i==len-1){
        len--;
        break;
      }
    }
  }
  for(int i = 0; i < len;i++)
    cout << a[i] << ' ';
  return 0;
}