#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    double d1 = 10/3; // Will give 3 because integer division
    double d2 = 10.0/3; // Will give 3.33333 because float division
    double d3 = 10.0/2.0; // Will give 5 if the number has no decimal part, it omits .0
    float  f1 = 22.0/7.0;
    double d4 = 22.0/7.0;

    float f2 = 3.14159265358979323846;
    double d5 = 3.14159265358979323846;

    cout<<d1<<endl;
    cout<<d2<<endl;
    cout<<d3<<endl;
    cout<<f1<<endl;
    cout<<d4<<endl;
    cout<<f2<<endl;
    cout<<d5<<endl;
    cout<<endl;

    cout<<fixed<<d1<<endl; // Will fix the precision to default i.e 6...It will not come in scientific format or anything
    cout<<fixed<<d2<<endl;
    cout<<fixed<<d3<<endl;
    cout<<fixed<<f1<<endl;
    cout<<fixed<<d4<<endl;
    cout<<endl;

    cout<<fixed<<setprecision(10)<<d1<<endl; //Changed default precision to 10
    cout<<fixed<<setprecision(10)<<d2<<endl;
    cout<<fixed<<setprecision(10)<<d3<<endl;
    cout<<fixed<<setprecision(15)<<f1<<endl;
    cout<<fixed<<setprecision(15)<<d4<<endl;
    
    cout<<fixed<<setprecision(20)<<f2<<endl;
    cout<<fixed<<setprecision(20)<<d5<<endl;

    cout<<endl;
    
    return 0;
}