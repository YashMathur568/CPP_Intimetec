#include <iostream>
#include <string>
#include <cmath>

void handleEValue(std::string str)
{
    int i = 0;
    while (str[i] == ' ' && str[i] != '\0')
    {
        i++;
    }
    double mantissa = 0;
    double exponent = 0;
    int mlength = 0;
    bool eAppeared = false;
    bool negativeExponent = false;
    bool dotAppeared = false;
    int afterdotLength = 0;
    int sign = 1;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }

    while (str[i] != '\0')
    {
        if (str[i] == 'e' && mlength == 0)
        {
            break;
        }
        if (str[i] == '.' && dotAppeared == false)
        {
            dotAppeared = true;
            i++;
        }
        if (str[i] == '.' && eAppeared == true)
        {
            break;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (eAppeared == false)
            {
                if (dotAppeared == true)
                {
                    afterdotLength++;
                }
                mantissa = mantissa * 10 + (str[i] - '0');
                mlength++;
                i++;
            }
            else
            {
                exponent = exponent * 10 + (str[i] - '0');
                i++;
            }
        }
        else if (str[i] == 'e')
        {
            if (mantissa == 0)
            {
                break;
            }
            else
            {
                if (eAppeared == false)
                {
                    i++;
                    eAppeared = true;
                    if (str[i] == '-')
                    {
                        negativeExponent = true;
                        i++;
                    }
                }
                else
                {

                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    mantissa = mantissa / pow(10, (mlength - 1));

    if (negativeExponent == false)
    {
        std::cout << sign * mantissa << "e+" << exponent + mlength - 1 - afterdotLength;
    }
    else
    {
        std::cout << sign * mantissa << "e-" << exponent - mlength + 1 + afterdotLength;
    }
}

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
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }
    double integralPart = 0;
    double fractionalPart = 0;
    bool decimalAppeared = false;
    int fracCounter = 0;

    double finalVal;

    while (str[i] != '\0')
    {
        if (str[i] == '-')
        {
            break;
        }
        if (str[i] == 'e')
        {
            handleEValue(str);
            exit(1);
        }
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
        else
        {
            break;
        }
    }
    fractionalPart = fractionalPart / pow(10, fracCounter);

    finalVal = sign * (integralPart + fractionalPart);
    return finalVal;
}

int main()
{
    std::cout << "Enter the string you want to get converted to double" << std::endl;
    std::string str;
    std::cin >> str;
    double result;
    result = my_atof(str);
    std::cout << result << std::endl;
    return 0;
}