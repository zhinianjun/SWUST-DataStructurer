#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Map{
    private:
        int** matrix;
        int size;
       
    public:
        Map(int size) : matrix(nullptr), size(size){
            matrix = new  int*[size];
            for(int i = 0; i < size; i++)
                matrix[i] =  new int[size];
            for(int i = 0; i < size;i++)
                for(int j = 0; j < size;j++)
                    cin >> matrix[i][j];
            
        }
        void bfs_str(string str, char start){
            int* visited = new int[size]{false};
            int pos = 0;
            queue<int> q;
            for(int i = 0; i < (int)str.length();i++)
                if(str[i] == start)
                {
                    pos = i;
                    break;
                }
            q.push(pos);
            visited[pos] = true;
            while(!q.empty()){
                for(int i = 0;i<size;i++){
                    if(matrix[q.front()][i] && !visited[i]){
                        visited[i] = true;
                        q.push(i);
                    } 
                }
                
                cout << str[q.front()];
                q.pop();
            }
           delete[] visited;
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
    cin >> n;
    string str;
    cin >> str;
    Map a(n);
    char start;
    cin >> start;
    a.bfs_str(str, start);

    return 0;
}