#include <iostream>
#include <string>

using namespace std;

class Circular_Sequence{
    private:
        int front, rear;
        int *seq;
        const int maxsize;
    public:
        Circular_Sequence(int size) : maxsize(size){
            front = rear = 0;
            seq =  new int[maxsize];
        }
        bool is_empty(){
            return front==rear ? true : false;
        }
        bool is_full(){
            if((rear+1)%maxsize == front)
                return true;
            else
                return false;
        }
        int length(){
            return (rear-front+maxsize)%maxsize;
        }
        bool push_back(int val){
            if(!is_full()){
                seq[rear] = val;
                rear = (rear+1)%maxsize;
                // cout << "Rear:"<< rear << '\n';
                return true;
            }else
                return false;
        }
        int pop_front(){
            if(!is_empty()){
                int temp = seq[front];
                front = (front+1)%maxsize;
                // cout << "Front:" << front << '\n';
                return temp;
            }else
                return -1;
        }
        void print(){
            int p = front;
            for(int i = 0; i<this->length();i++){
                cout << seq[p%maxsize] << ' ';
                p++;
            }
        }

        ~Circular_Sequence(){
            delete[] seq;
        }

};

int main(){
    int size;
    int count;
    cin >> size >> count;
    Circular_Sequence a(size);
    for(int i = 0;i<count;i++){
        string oprate;
        cin >> oprate;
        if(oprate == "in"){
            int num;
            cin >> num;
            a.push_back(num);
            continue;
        }else if(oprate == "out"){
            a.pop_front();
            continue;
        }
    }
    a.print();
    return 0;
}