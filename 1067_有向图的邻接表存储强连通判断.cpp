#include <iostream>
#include <list>

using namespace std;


void dfs(int pos, list<int>* l, int* visited){
    if(l[pos].empty())
      return;
    list<int>::const_iterator = l[pos].begin();
    for(int i = 0; i < l[pos].size;i++){
      dfs()
    }
}
int main(){
    int n, m;
    cin >> n >>m;
    getchar();

    int pos, edge;
    list<int>* l = new list<int>[n];
    int* visited  = new int[n]{false};

    for(int i = 0;i<m;i++){
        scanf("%d %d", &pos, &edge);
        l[pos].push_back(edge);
    }
  for(int i = 0; i < n;i++)
    if(!l[i].empty()) start = i;
  dfs(start, l);
    
    bool is_strong = true;
    for(int i = 0; i < n;i++){
        if(visited[i]==false)
            is_strong = false;
    }
    if(is_strong)
        cout << "YES";
    else
        cout << "no";
    delete[] l;
    delete[] visited;
    return 0;
}