#include <iostream>
#include <string>

double pow(double base, int exponent)
{
    double result = 1.0;
    bool isNegative = false;
    if (exponent < 0)
    {
        isNegative = true;
        exponent = -exponent;
    }
    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }
    return isNegative ? 1.0 / result : result;
}

void skipSpaces(std::string &str, int &i)
{
    while (str[i] == ' ' && str[i] != '\0')
    {
        i++;
    }
}

int parseSign(std::string &str, int &i)
{
    if (str[i] == '-')
    {
        i++;
        return -1;
    }
    else if (str[i] == '+')
    {
        i++;
        return 1;
    }
    return 1;
}

double parseUnsignedInteger(std::string &str, int &i)
{
    double result = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

double parseFraction(std::string &str, int &i, int &fracLen)
{
    double frac = 0;
    fracLen = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        frac = frac * 10 + (str[i] - '0');
        fracLen++;
        i++;
    }

    return frac;
}

double handleEValue(std::string &str)
{
    int i = 0;
    skipSpaces(str, i);

    int sign = parseSign(str, i);
    double mantissa = 0;
    int afterdotLength = 0;
    bool dotAppeared = false;

    while (str[i] != '\0' && str[i] != 'e' && str[i] != 'E')
    {
        if (str[i] == '.' && !dotAppeared)
        {
            dotAppeared = true;
            i++;
            continue;
        }

        if (str[i] >= '0' && str[i] <= '9')
        {
            mantissa = mantissa * 10 + (str[i] - '0');
            if (dotAppeared)
                afterdotLength++;
        }
        else
        {
            break;
        }
        i++;
    }

    bool negativeExponent = false;
    double exponent = 0;

    if (str[i] == 'e' || str[i] == 'E')
    {
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

        exponent = parseUnsignedInteger(str, i);
    }

    mantissa = mantissa / pow(10, afterdotLength);
    int finalPower = negativeExponent ? -(int)exponent : (int)exponent;
    return sign * mantissa * pow(10, finalPower);
}

double my_atof(std::string &str)
{
    int i = 0;
    skipSpaces(str, i);
    int sign = parseSign(str, i);

    double integralPart = parseUnsignedInteger(str, i);
    double fractionalPart = 0;
    int fracLen = 0;

    if (str[i] == '.')
    {
        i++;
        fractionalPart = parseFraction(str, i, fracLen);
    }

    if (str[i] == 'e' || str[i] == 'E')
    {
        return handleEValue(str);
    }

    fractionalPart = fractionalPart / pow(10, fracLen);
    return sign * (integralPart + fractionalPart);
}

int main()
{
    std::cout << "Enter the String: ";
    std::string str;
    std::cin >> str;

    double result = my_atof(str);
    std::cout << "Converted value: " << result << std::endl;

    return 0;
}
