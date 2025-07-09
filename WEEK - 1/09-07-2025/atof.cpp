// Atof Function All Edge Cases

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    string str = "0";
    // double result;
    // double res;
    // result = atof(str.c_str());
    // result = atof("23");
    // cout << result << endl;
    // cout << res << endl;

    cout << atof("") << endl;
    cout << atof("1.4e7") << endl;
    cout << atof("123") << endl;
    cout << atof("123.23") << endl;
    cout << atof("123.23.23") << endl;
    cout << atof("-123.23.23") << endl;
    cout << atof("e23") << endl;
    cout << atof("32e23") << endl;
    cout << atof("32ea23") << endl;
    cout << atof("ea") << endl;
    cout << atof("-34e23") << endl;
    cout << atof("   -23.34.34") << endl;
    return 0;
}