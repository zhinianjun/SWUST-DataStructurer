#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Map{
    private:
        int** matrix;
        int size;
        void dfs(int pos, int** matrix, int size, vector<bool>& visited, vector<int> path, int target){
            path.push_back(pos);
            visited[pos] = true;
            // cout << pos << endl;
            if(path.back() == target)
            {
                for(int num : path)
                    cout << num;
                cout << endl;
            }else{
               
                for(int i = 0; i < size;i++)
                    if(matrix[pos][i] != 0 && !visited[i]){
                         dfs(i, matrix, size, visited, path, target);
                        //  cout << i << endl;
                    }
                       
            }
            path.pop_back();
            visited[pos] = false;
        }
    public:
        Map(int size) : matrix(nullptr), size(size){
            matrix = new  int*[size];
            for(int i = 0; i < size; i++)
                matrix[i] =  new int[size];
            for(int i = 0; i < size;i++)
                for(int j = 0; j < size;j++)
                    cin >> matrix[i][j];
            
        }
        void path(int start, int target){
            vector<int> p;
            vector<bool> visited(size, false);
           
            dfs(start, matrix, size, visited, p, target);
        }
        ~Map(){
            for(int i = 0; i < size;i++)
                delete[] matrix[i];
            delete[] matrix;
            matrix = nullptr;
        }
};
int main(){
    int n;
    int start, target;
    cin >> n;
    cin >> start >> target;
    Map a(n);
    a.path(start, target);
    return 0;
}