#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    getchar();
    bool** matrix = new bool*[n] ;
    for(int i = 0; i < n;i++)
        matrix[i] = new bool[n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            matrix[i][j] = 0;
    }

    char pos;
    for(int i = 0; i < n;i++){
            while(true){
            cin.get(pos);
            // cout << pos <<endl;
            if(pos == '\n')
                break;
            else if(pos == ' ')
                continue;
            matrix[i][pos-'0'] = 1;
            }
        // if(i<n-1)
        //     getchar();
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << matrix[i][j];
        cout<< endl;
    }
    for(int i = 0; i < n;i++)
        delete[] matrix[i];
    delete[] matrix;
    return 0;
}