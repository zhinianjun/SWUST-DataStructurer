#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef struct Sequence_List{
    int data[MAXSIZE];
    int length;
}Sqlist;

void Init(Sqlist*& L, int* a, int size){
    L = new Sqlist;
    for(int i = 0;i<size;i++)
        L->data[i] = a[i];
    L->length = size;
}

void Destroy(Sqlist*& L){
    delete L;
}
int main(){
    Sqlist* a;
    int num;
    cin >> num;
    int* tmp = new int[num];
    int* count = new int[num];
    for(int i = 0;i<num;i++) cin >> tmp[i];
    Init(a, tmp, num);

    for(int i = 0;i< a->length;i++){
        for(int j = 0;j<a->length;j++){
            if(a->data[i] == a->data[j])
                count[i] = count[i]+1;
        }
    }

    int count_max = 0;
    int val_max = 0;
    for(int i = 0; i < a->length;i++){
        if(count[i] > count_max){
            if(a->data[i] >= val_max){
                count_max = count[i];
                val_max = a->data[i];
            }
        }
    }
    cout << val_max;
    return 0;
}