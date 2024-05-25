    #include <iostream>
    #include <string>

    using namespace std;

    class Map{
        private:
            int** matrix;
            int size;
            void dfs(int pos, int** matrix, int* visited, int size, string str){
                if(visited[pos])
                    return;
                visited[pos] = true;
                cout << str[pos];
                for(int i = 0 ;i < size; i++)
                    if(matrix[pos][i]!=0)
                    {
                        // cout << i << endl;
                        dfs(i, matrix,visited ,size, str);
                    }
                        
                
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
            void dfs_str(string str, char start){
                int* visited = new int[size]{false};
                int pos = 0;
                for(int i = 0; i < (int)str.length();i++)
                    if(str[i] == start)
                    {
                        pos = i;
                        break;
                    }
                dfs(pos, matrix, visited, size, str);
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
        a.dfs_str(str, start);

        return 0;
    }