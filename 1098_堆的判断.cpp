#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int* a = new int[n];
  for(int i = 0; i<n;i++)
    cin >> a[i];
  for(int i = n / 2 -1; i>=0;i--){
    int lchild = i * 2 + 1;
    int rchild = i * 2 + 2;
    if(lchild<n && a[lchild] < a[i])
    {
      cout << "No";
      return 0;
    }
    if(lchild<n && a[rchild] < a[i])
    {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  delete[] a;
  return 0;
}