#include "stringlib.hh"

bool startsWith(std::string str, std::string prefix){
    // TODO: Fill your code!!
    for(int i=0;i<prefix.length();i++)
    {
        if(str[i] != prefix[i]) return false;
    }
    return true;
}

bool startsWith(std::string str, char prefix){
    // TODO: Fill your code!!
    if(str[0] == prefix)    return true;
    else                    return false;
}


bool endsWith(std::string str, std::string suffix){
    // TODO: Fill your code!!
    for(int i=0;i<suffix.length();i++)
    {
        if(str[str.length()-1-i] != suffix[suffix.length()-1-i]) return false;
    }
    return true;
}

bool endsWith(std::string str, char suffix){
    // TODO: Fill your code!!
    if(str[str.length()-1] == suffix)       return true;
    else                                    return false;
}

std::string integerToString(int n){
    // TODO: Fill your code!!
    // Hint: Use push_back function of std::string
    std::string number;

    //if zero
    if(n == 0)
    {
        number = "0";
        return number;
    }

    while(n != 0)
    {
        char next = n % 10 + 48;
        number = next + number;
        n/=10;
    }
    return number;
}

std::string realToString(double d){
    // TODO: Fill your code!!
    std::string str1;

    //if zero
    if(d == 0.0)
    {
        str1 = "0.";
        return str1;
    }

    int number1 = int(d);
    while(number1 != 0)
    {
        char next = number1 % 10 + 48;
        str1 = next + str1;
        number1/=10;
    }

    std::string str2;
    double number2 = d - int(d);
    while(number2 != 0.0)
    {
        number2 *= 10.0;
        char next = int(number2) + 48;
        number2 -= int(number2);
        str2 = str2 + next;
    }

    return str1 + "." + str2;
}

int stringToInteger(std::string str){
    // TODO: Fill your code!!
    int number = 0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '.')   break;
        number *= 10;
        number += (str[i] - 48);
    }
    return number;
}

double stringToReal(std::string str){
    // TODO: Fill your code!!
    double number1 = 0, number2 = 0;
    int i;
    for(i=0;i<str.length();i++)
    {
        if(str[i] == '.')   break;
        number1 *= 10;
        number1 += (str[i] - 48);
    }
    for(i=str.length()-1;i>=0;i--)
    {
        if(str[i] == '.')   break;
        number2 /= 10;
        number2 += (str[i] - 48);
    }
    number2 /= 10;
    return number1 + number2;
}

std::string toLowerCase(std::string str){
    // TODO: Fill your code!!
    std::string low;
    for(int i=0;i<str.length();i++)
    {
        char next;
        if(str[i] >= 'A' && str[i] <= 'Z')      next = str[i] + 32;
        else                                    next = str[i];
        low = low + next;
    }
    return low;
}

std::string toUpperCase(std::string str){
    // TODO: Fill your code!!
    std::string upper;
    for(int i=0;i<str.length();i++)
    {
        char next;
        if(str[i] >= 'a' && str[i] <= 'z')      next = str[i] - 32;
        else                                    next = str[i];
        upper = upper + next;
    }
    return upper;
}

bool comapreIgnoreCaseType(std::string s1, std::string s2){
    // TODO: Fill your code!!
    // Hint: exploit the function you already implemented, "toLowerCase" or "toUpperCase".
    if(s1.length() != s2.length())  return false;

    std::string news1, news2;
    news1 = toLowerCase(s1);
    news2 = toLowerCase(s2);
    for(int i=0;i<news1.length();i++)
    {
        if(news1[i] != news2[i])    return false;
    }
    return true;
}

std::vector<std::string> trim(std::string str){
    // TODO: Fill your code!!
    std::vector<std::string> vec;
    std::string next;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == ' ' || i == str.length()-1)
        {
            vec.push_back(next);
            next = "";
        }
        else    next = next + str[i];
    }
    return vec;
}
