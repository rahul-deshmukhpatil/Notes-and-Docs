#include <iostream>
using namespace std;
class students{
    private:
        int i;
        float f;

    public:
        void add(int b){
            i=b;
            cout << "First Int: " << i;
        }
        void add(float c){
            f=c;
            cout << "Second Int: " << f;
        }

};

int main(){
    students obj;
    obj.add(9);
    obj.add(5.5);
}
