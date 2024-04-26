#include <iostream>

using namespace std;

typedef struct Sequence_List{
  int* sql;
  int length;
} Sql;

void Init(Sql*& a, int b[], int size){
  a->sql = new int[size];
  for(int i = 0; i < size; i++)
    a->sql[i] = b[i];
  a->length = size;
}

void Free(Sql* a){
  delete[] a->sql;
}
int main(){
  Sql* a = nullptr;
  int num;
  cin >> num;
  int* tmp = new int[num];

  // int less_num = 0;
  // int more_num = 0;
  // int* less_than = new int[num];
  // int* more_than = new int[num];

  for(int i = 0; i < num; i++)
    cin >> tmp[i];
  
  Init(a, tmp, num);
  
  int origin = a->sql[0];
  for(int i = num-1; i > 0; i--)
  {
    if(a->sql[i] <= a->sql[0])
    {
      cout << a->sql[i] << ' ';

    }
  }

  // cout << origin << ' ';
// for(int i = 0; i < num; i++)
//     cout << a->sql[i] << ' ';

  // for(int i = 1; i < num; i++)
  // {
  //   if(a->sql[i] > a->sql[0]){
  //     // more_than[more_num] = a->sql[i];
  //     // more_num++;
  //     cout << a->sql[i] << ' ';
  //   }
  // }

  // cout << less_num << '\n';
  // cout << more_num << '\n';
  // for(int i = 0; i < less_num; i++)
  //   cout << less_than[i] << ' ';
  // a->sql[less_num] = origin;

  // for(int i = 0;i<less_num;i++)
  //   a->sql[i] = less_than[i];
  // for(int i = less_num+1;i<num;i++)
  //   a->sql[i] = more_than[i];
  // for(int i = 0; i < num; i++)
  //   cout << a->sql[i] << ' ';

  Free(a);
  delete[] tmp;
  // delete[] less_than;
  // delete[] more_than;
  return 0;
}