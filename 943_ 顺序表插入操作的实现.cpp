#include <iostream>

using namespace std;

class Sequence{
    private:
        int* a;
        int length;
        int numbers;
    public:
        Sequence(int len) : length(len), numbers(0){
            a = new int[len];
        }

        int insert(int elem, int num){
            int pos = -1;
            
            for(int i = 0; i < numbers; i++) 
                if(a[i] == elem) pos = i;

            if(pos == -1){
                int* temp = a;
                length++;
                a = new int[length];
                for(int i = 0; i < length -1; i++){
                    a[i] = temp[i];
                }
                delete[] temp;
                a[length-1] = num;
                numbers++;
            }

            return 0;
        }
        
       int append(int num){
        a[numbers] = num;
        numbers++;
        return 1;
       }

        void print(){
            for(int i = 0; i< numbers; i++)
                cout << a[i] << ' ';
            cout << '\n';
        }
        ~Sequence(){
            delete[] a;
        }

};

int main(){
    int length;
    cin >> length;
    Sequence a(length);
    for(int i = 0; i < length; i++)
    {
        int temp;
        cin >> temp;
        a.append(temp);
    }

    a.print();
    int elem, num;
    cin >> elem;
    cin >> num;
    a.insert(elem, num);
    a.print();
    return 0;
}