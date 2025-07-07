#include <iostream>
#include <cstring>

using namespace std;

class Stock{
    private:
        char* name;

    public:
        Stock(const char* n){
            name = new char[strlen(n)+1];
            strcpy(name,n);
        }
        Stock(const Stock &s){
            name = new char[strlen(s.name) + 1];
            strcpy(name, s.name);
        }

        void print() {
        cout << "Name: " << name << endl;
        }

        ~Stock() {
            delete[] name;
        }
};

int main(){

    Stock s1("Apple");
    Stock s2=s1;
    s1.print();
    s2.print();

    return 0;

}