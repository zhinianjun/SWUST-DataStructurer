#include <iostream>
#include <utility>

using namespace std;

class HashTable{
    private:
        const int maxsize;
        
        int* table;
        int hash_function(int data){
            int pos = data % maxsize;
            while(table[pos] != -1) pos = (pos + 1) % maxsize;
            return pos;
        }
    public:
        HashTable(int size) : maxsize(size), table(NULL){
        
            table = new int[size];
            for(int i = 0; i < maxsize; i++) table[i] = -1;
        }
        void insert(int data){
            int pos = hash_function(data);
            // cout << pos << endl;
            table[pos] = data;
        }
        pair<int, int> find(int data){
            int pos = data % maxsize;
            int times = 0;
            // bool is_found = false;
            while(table[pos] != -1){
                times++;
                if(table[pos] == data) return make_pair(pos, times);
                pos = (pos + 1)%maxsize;
            }
            return make_pair(pos, -1);
        }
        ~HashTable(){
            delete[] table;
        }
};
int main(){
    int t_size, num_len;
    cin >> t_size >> num_len;
    HashTable a(t_size);

    int num;
    for(int i = 0; i < num_len; i++){
        cin >> num;
        a.insert(num);
    }

    cin >> num;
    if(a.find(num).second== -1)
        cout << -1;
    else
        cout << a.find(num).first << ',' << a.find(num).second;
}