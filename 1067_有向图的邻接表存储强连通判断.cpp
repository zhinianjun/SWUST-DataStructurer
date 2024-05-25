#include <iostream>
#include <list>

using namespace std;

void dfs(int pos, list<int>* l, int* visited){
    if(l[pos].empty())
        return;
    visited[pos] = true;
    list<int>::const_iterator a = l[pos].begin();
    while(visited[*a]==false) a++;
    dfs(*a, l, visited);
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