#include <iostream>

using namespace std;

class Map{
    private:
        const int size;
        bool** matrix;
        void dfs(int n, bool** matrix, bool* visited, int size){
            if(visited[n])
                return;
            visited[n] = true;
            for(int i = 0;i<size;i++)
                if(matrix[n][i] == 1)
                    dfs(i, matrix, visited, size);
        }
    public:
        Map(int size) : size(size), matrix(NULL){
            matrix = new bool*[size];
            for(int i = 0; i < size; i++)
                matrix[i] = new bool[size];
            
            for(int i = 0;i<size;i++)
                for(int j = 0; j < size; j++)
                    cin >> matrix[i][j];
        }
        int component(){
            int component = 0;
            bool* visited = new bool[size]{false};

            for(int i = 0; i < size;i++){
                if(!visited[i]){
                    dfs(i, matrix, visited, size);
                    component++;
                }
            }
            delete[] visited;
            return component;
        }
        ~Map(){
            for(int i = 0; i < size;i++)
                delete[] matrix[i];
            delete[] matrix;
            matrix = nullptr;
        }
};
int main(){
    int n;  cin >> n;

    Map a(n);
    cout << a.component();
    return 0;
}