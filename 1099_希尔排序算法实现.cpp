#include <iostream>

using namespace std;

void ShellSort(int* arr, int n, int d){
  for(int i = d +1;i<=n;i++){
    if(arr[i] < arr[i-d]){
      arr[0] = arr[i];
      int j;
      for(j= i - d; j>0&&arr[0] < arr[j]; j=j-d)
      arr[j+d] = arr[j];
      arr[j+d] = arr[0];
    }
  }
}
int main(){
  int n;
  cin >> n;
  int* arr = new int[n+1];
  for(int i = 1; i <= n;i++)
    cin >> arr[i];
  ShellSort(arr, n, 5);
  for(int i = 1; i <= n;i++)
    cout << arr[i] << ' ';
  delete[] arr;
  return 0;
}