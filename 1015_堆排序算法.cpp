#include <iostream>

using namespace std;

void Swap(int& a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void MinHeap(int a[], int n, int i){
    int smallest = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    if(lchild < n && a[lchild] < a[smallest])
        smallest = lchild;
    if(rchild < n && a[rchild] < a[smallest])
        smallest = rchild;

    if(smallest != i){
        Swap(a[i], a[smallest]);
        MinHeap(a, n, smallest);
    }
}
// void Heapsort(){

// }
void buildMinHeap(int a[], int n){
    for(int i = n / 2 - 1; i >= 0; i--)
        MinHeap(a, n, i);
}

int main(){
    int num;
    cin >> num;
    int* a = new int[num];
    for(int i = 0; i < num; i++) cin >> a[i];
    buildMinHeap(a, num);
    for(int i = 0; i < num; i++) cout << a[i] << ' ';

    delete[] a;
    return 0;
}