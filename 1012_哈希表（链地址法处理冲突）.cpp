#include <iostream>
#include <list>

using namespace std;

class HashTable{
    private:
        const int maxsize;
        list<int>* l;
        
    public:
        HashTable(int size) : maxsize(size){
            l = new list<int>[maxsize];
        }
        int hash_function(int val){
            return val % maxsize;
        }
        void insert(int data){
            int pos = hash_function(data);
            l[pos].push_back(data);
        }
        int find(int data){
            int times = 0;
            int pos = hash_function(data);

            if (l[pos].empty()) return -1;
            list<int>::const_iterator a = l[pos].begin();
            while(a != l[pos].end()){
                times++;
                if(*a == data) return times;
                a++;
            }
            return -1;
        }
        ~HashTable(){
            delete[] l;
        }
};

int main(){
    int hash_len;
    cin >> hash_len;
    int num_len;
    cin >> num_len;

    HashTable a(hash_len);
    int num;
    for(int i = 0; i <num_len; i++)
    {
        cin >> num;
        a.insert(num);
    }

    cin >> num;
    if(a.find(num) != -1)
        cout <<a.hash_function(num) << ',' <<a.find(num);
    else
        cout << -1;
    return 0;
}