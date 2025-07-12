#include <iostream>
#include <string>

double pow(double base, int exponent)
{
    double result = 1.0;
    bool isNegative = false;
    if (exponent < 0)
    {
        isNegative = true;
        exponent = -1 * exponent;
    }
    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }
    if (isNegative)
    {
        result = 1.0 / result;
    }
    return result;
}

double handleEValue(const std::string &str)
{
    int i = 0;
    while (str[i] == ' ' && str[i] != '\0')
    {
        i++;
    }

    double mantissa = 0;
    double exponent = 0;
    int mLength = 0;
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
        if (str[i] == '.' && !dotAppeared)
        {
            dotAppeared = true;
            i++;
            continue;
        }

        if (str[i] == 'e')
        {
            eAppeared = true;
            i++;
            if (str[i] == '-')
            {
                negativeExponent = true;
                i++;
            }
            else if (str[i] == '+')
            {
                i++;
            }
            break;
        }

        if (str[i] >= '0' && str[i] <= '9')
        {
            if (!eAppeared)
            {
                mantissa = mantissa * 10 + (str[i] - '0');
                if (dotAppeared)
                {
                    afterdotLength++;
                }
                mLength++;
            }
            i++;
        }
        else
        {
            break;
        }
    }

    while (str[i] >= '0' && str[i] <= '9')
    {
        exponent = exponent * 10 + (str[i] - '0');
        i++;
    }

    mantissa = mantissa / pow(10, afterdotLength);

    int power = (negativeExponent) ? -(int)exponent : (int)exponent;

    return sign * mantissa * pow(10, power);
}

double my_atof(const std::string &str)
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

    while (str[i] != '\0')
    {
        if (str[i] == 'e' || str[i] == 'E')
        {
            return handleEValue(str);
        }

        if (str[i] >= '0' && str[i] <= '9')
        {
            if (!decimalAppeared)
            {
                integralPart = integralPart * 10 + (str[i] - '0');
            }
            else
            {
                fractionalPart = fractionalPart * 10 + (str[i] - '0');
                fracCounter++;
            }
        }
        else if (str[i] == '.')
        {
            if (!decimalAppeared)
            {
                decimalAppeared = true;
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
        i++;
    }

    fractionalPart = fractionalPart / pow(10, fracCounter);
    return sign * (integralPart + fractionalPart);
}

int main()
{
    std::cout << "Enter the String";
    std::string str;
    std::cin >> str;

    double result = my_atof(str);
    std::cout << "Converted value: " << result << std::endl;

    return 0;
}
