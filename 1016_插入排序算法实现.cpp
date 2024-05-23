#include <iostream>

using namespace std;

void InsertSort(int a[], int n){
    int i, j;
    for(i = 2; i <= n; i++){
        a[0] = a[i];
    for(j = i -1; a[0] < a[j]; j--)
        a[j+1] = a[j];
    a[j+1] = a[0];
    return;
    }

}
int main(){
    int num;
    cin >> num;
    int* a = new int[num+1];
    for(int i = 1; i <= num; i++) cin >> a[i];
    InsertSort(a, num);
    for(int i = 1; i <= num; i++) cout << a[i] << ' ';
    delete[] a;
    return 0;
}