#include <iostream>

using namespace std;


//Abstract Class
class Trading{
    public:
        //Pure Virtual Function
        virtual void BuyAtLow()=0;
        virtual void SellAtHigh()=0;

        void MakeTrade(){
            BuyAtLow();
            SellAtHigh();
        }
};

class TradeApple : public Trading{
    public:
        void BuyAtLow() override{
            cout<<"Buy Apple At Low"<<endl;
        }
        void SellAtHigh() override{
            cout<<"Sell Apple At High"<<endl;
        }
};

class TradeGoogle : public Trading{
    public:
        void BuyAtLow() override{
            cout<<"Buy Google At Low"<<endl;
        }
        void SellAtHigh() override{
            cout<<"Sell Google At High"<<endl;
        }
};

int main(){
    TradeApple a;
    TradeGoogle g;
    a.MakeTrade();
    g.MakeTrade();
    return 0;
}