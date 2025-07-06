#include <iostream>

using namespace std;

class Stock{
    private:
        string name;
        int price;

    public:
        Stock(string name,int price){
            this->name=name;
            this->price=price;
        }

        friend void comparePrice(Stock &s1,Stock &s2);

        void display(){
            cout<<"Stock Name: "<<name<<endl;
            cout<<"Stock Price: "<<price<<endl;
        }
    };

    void comparePrice(Stock &s1,Stock &s2){
        if(s1.price>s2.price){
            cout<<s1.name<<" is costlier than "<<s2.name;
        }
        else{
            cout<<s2.name<<" is costlier than "<<s1.name;
        }
    }

int main(){
    Stock s1("Apple",300);
    Stock s2("Google",200);
    comparePrice(s1,s2);
    return 0;
}