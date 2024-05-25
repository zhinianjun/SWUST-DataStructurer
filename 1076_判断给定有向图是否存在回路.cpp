#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Map{
    private:
        int** matrix;
        const int size;
        bool dfs(int pos, int** matrix, vector<bool>& visited, vector<bool>& restack, int size){
            visited[pos] = true;
            restack[pos] = true;
            
            for(int i = 0; i < size; i++){
                if(matrix[pos][i]!=0 && !visited[i]){
                    if(dfs(i, matrix, visited, restack, size)) return true;
                }
                else if(matrix[pos][i]!=0 && visited[i]){
                    if(restack[i])
                        return true;
                }
            }
            // visited[pos] = false;
            restack[pos] = false;
            return false;
        }
    public:
        Map(int size, int edge) : matrix(nullptr), size(size){
            matrix = new  int*[size];
            for(int i = 0; i < size; i++)
                matrix[i] =  new int[size]{0};
            string nodes;
            char node;
            for(int i = 0; i < size; i++)
            {
                cin >> node;
                nodes+=node;
            }
            // cout << nodes;
            for(int i = 0; i < edge;i++){
                char n1, n2;
                cin >> n1 >> n2;
                matrix[nodes.find(n1)][nodes.find(n2)] = 1;
            }
            // for(int i =0;i<size;i++){
            //     for(int j = 0; j < size;j++)
            //         cout << matrix[i][j];
            //     cout << endl;
            // }
        }
        bool is_circle(){
            vector<bool> visited(size, false);
            vector<bool> restack(size, false);
            
            for(int i =0; i< size;i++){
                if(!visited[i])
                    if(dfs(i, matrix, visited, restack, size))
                        return true;
            }
            return false;
        }
        ~Map(){
            for(int i = 0; i < size;i++)
                delete[] matrix[i];
            delete[] matrix;
            matrix = nullptr;
        }
};
int main(){
    int size, edge;
    cin >> size >> edge;
    Map a(size, edge);
    if(a.is_circle())
        cout << "yes";
    else
        cout << "no";
    return 0;
}