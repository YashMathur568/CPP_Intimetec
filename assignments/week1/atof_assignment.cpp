#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
double my_atof(std::string str)
{
    int i = 0;
    while (str[i] == ' ' && str[i] != '\0')
    {
        i++;
    }
    int sign = 1;
    if (str[i] == '-')
    {
        sign = -1;
    }
    double integralPart = 0;
    double fractionalPart = 0;
    bool decimalAppeared = false;
    int fracCounter = 0;

    double finalVal;

    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (decimalAppeared == false)
            {
                integralPart = integralPart * 10 + (str[i] - '0');
                i++;
            }
            else
            {
                fractionalPart = fractionalPart * 10 + (str[i] - '0');
                fracCounter++;
                i++;
            }
        }
        else if (str[i] == '.')
        {
            if (decimalAppeared == false)
            {
                decimalAppeared = true;
                i++;
            }
            else
            {
                break;
            }
        }
    }
    fractionalPart = fractionalPart / pow(10, fracCounter);

    finalVal = sign * integralPart + fractionalPart;
    return finalVal;
}

int main()
{
    std::cout << "Enter the string you want to get converted to double" << std::endl;
    std::string str;
    std::cin >> str;
    double result;
    result = my_atof(str);
    std::cout << std::fixed << std::setprecision(10) << result << std::endl;
    return 0;
}