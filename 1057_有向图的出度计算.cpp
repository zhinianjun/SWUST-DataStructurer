#include <iostream>
#include <list>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    list<int>* a = new list<int>[n];
    int p, q;
    for(int i = 0; i < m; i++){
      scanf("%d %d", &p, &q);
      a[p].push_back(q);
    }
    
    for(int i = 0; i < n;i++){
      if(a[i].empty())
      {
        cout << 0 << endl;
        continue;
      }
      int out_deg = 0;
      list<int>::const_iterator start = a[i].begin();
      while(start!=a[i].end())
      {
        out_deg++;
        start++; 
      }
      cout << out_deg << endl;
    }
    delete[] a;
    return 0;
}