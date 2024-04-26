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

        int insert(int num,int pos){
            if(pos<length){
                a[pos] = num;
                numbers++;
                return 1;
            }
            return 0;
        }
        
        int append(int num){
            if(numbers < length){
                a[numbers] = num;
                numbers++;
                return 1;
            }
            return 0;
        }

        int get_len() const{
            return this->length;
        }
        int getelem(int pos) const{
            return a[pos];
        }
        void print(){
            // cout << this->numbers << '\n';
        
            for(int i = 0; i < this->numbers; i++)
                cout << a[i] << ' ';
            // cout << "\n";
        }

    Sequence add(Sequence& a) const{
    Sequence temp(this->length + a.length);
    cout << temp.get_len() << "\n";
    int i = 0, j = 0;
    while (i < this->numbers && j < a.numbers) {
        if (this->getelem(i) < a.getelem(j)) {
            temp.append(this->getelem(i));
            i++;
        } else if (this->getelem(i) > a.getelem(j)) {
            temp.append(a.getelem(j));
            j++;
        } else { // 当元素相等时
            temp.append(this->getelem(i));
            temp.append(a.getelem(j)); // 重复添加两个相等元素
            i++;
            j++;
        }
    }
    
    // 将剩余元素添加到temp中
    while (i < this->numbers) {
        temp.append(this->getelem(i));
        i++;
    }
    while (j < a.numbers) {
        temp.append(a.getelem(j));
        j++;
    }
    
    return temp;
}
    

        ~Sequence(){
            delete[] a;
        }

};

int main(){
    int len;
    cin >> len;
    Sequence a(len);

    for(int i = 0; i < len; i++)
    {
        int temp;
        cin >> temp;
        a.append(temp);
    }
    // a.print();
    // cout << a.getelem(0) << ' ' << a.getelem(1) << "\n\n";

    cin >> len;
    Sequence b(len);
    for(int i = 0; i < len; i++)
    {
        int temp;
        cin >> temp;
        b.append(temp);
    }
    // b.print();
    Sequence res = a.add(b);
    res.print();
    return 0;
}