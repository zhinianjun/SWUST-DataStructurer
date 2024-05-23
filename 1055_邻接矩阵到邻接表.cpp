#include <iostream>
#include <list>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool** matrix = new bool*[n] ;
    for(int i = 0; i < n;i++)
        matrix[i] = new bool[n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    list<int>* table = new list<int>[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j]) table[i].push_back(j);
        }
    }
    for(int i = 0; i< n;i++){
        if(table[i].empty()) continue;
        list<int>::const_iterator a = table[i].begin();
        while(a != table[i].end()){
            cout << *a;
            a++;
        }
    //     if(i==n-1) break;
    //     cout << endl;
    // }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n;j++){
    //         if(matrix[i][j]) cout << j;
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < n;i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] table;
    return 0;
}