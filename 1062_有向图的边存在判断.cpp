#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    bool** matrix = new bool*[5];
    for(int i = 0; i < n;i++)
        matrix[i] = new bool[n];
    for(int i = 0;i<n;i++){
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    
    if(matrix[a][b] == 1 || matrix[b][a] == 1)
        cout << "yes";
     else
        cout << "no";
        
    for(int i = 0; i< n;i++)
        delete[] matrix[i];
    delete[] matrix;
    
    return 0;
}