#include <iostream>

using namespace std;

int main(){
    int size;
    cin >> size;
    int* seq = new int[size+1];
    for(int i = 1; i <= size; i++) cin >> seq[i];
   
    int left_move;
    cin >> left_move;
    if(left_move < 0 || left_move > size) {
        cout << "error!";
        return 0;
    }
    
    
    int a[100];
    int b[100];

    for(int i = 1; i <= left_move;i++) a[i] = seq[i];
    // for(int i = 1; i <= left_move; i++) cout << a[i] << ' ';

    for(int i = left_move+1;i<=size;i++) b[i-left_move] = seq[i];
    // for(int i = 1; i <= size; i++) cout << b[i] << ' ';

    for(int i = 1;i<=size-left_move;i++) seq[i] = b[i];
    // for(int i = 1; i <= size-left_move; i++) cout << seq[i] << ' ';
    // cout << endl;

    for(int i = 1;i<=size-left_move;i++) seq[i] = b[i];
    for(int i = size-left_move+1;i<=size;i++) seq[i] = a[i+left_move-size];
    
    for(int i = 1; i <= size; i++) cout << seq[i] << ' ';
    delete[] seq;
    return 0;
}