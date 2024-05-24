#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    bool** matrix = new bool*[5];
    for(int i = 0; i < n;i++)
        matrix[i] = new bool[n];
    for(int i = 0;i<n;i++){
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    int* deg = new int[n]{0};
    
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++)
            if(matrix[i][j] == 1)
                deg[i]++;
    }
    int max_deg = 0;
    for(int i = 0;i<n;i++)
        if(deg[i] > max_deg)
            max_deg = deg[i];
    cout << max_deg << endl;
    for(int i = 0; i < n; i++)
        if(deg[i] == max_deg)
            cout << i;
    
    for(int i = 0; i< n;i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] deg;
    return 0;
}