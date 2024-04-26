#include <iostream>

using namespace std;

class Queue{
    private:
        int front;
        int tail;
        int* base;
        const int maxsize;

    public:
        Queue(int size) :  front(0), tail(0), maxsize(size+1){
            base = new int[this->maxsize];
        }

        bool is_full(){
            if((tail+1)%maxsize == front)
            return true;
        return false;
        }

        int length(){
            return (tail - front + maxsize) % maxsize;
        }
        bool push(int data){
            if(!this->is_full()){
                base[tail] = data;
                tail = (tail + 1)%maxsize;
                return 1;
            }
            return 0;
        }

        int pop(){
            if(front != tail){
                int x = this->base[front];
                front = (front + 1)%maxsize;
                return x;
            }
            return -1;
        }

        void print(){
            int p = front;
            for(int i = 0; i < this->length(); i++){
                cout << base[p%maxsize] << ' ';
                p++;
            }
            cout << endl;
        }

        ~Queue(){
            delete[] base;
            base = nullptr;
        }
};

int main(){
    Queue queue1(4);
    cout << "Now this queue have " << queue1.length() << " numbers" << endl;
    queue1.push(1);
    cout << "Now this queue have " << queue1.length() << " numbers" << endl;
    queue1.push(2);
    queue1.push(3);
    queue1.push(4);
    queue1.print();

    queue1.pop();
    queue1.print();
    queue1.push(5);
    queue1.print();
    cout << "Now this queue have " << queue1.length() << " numbers" << endl; 
    return 0;
}