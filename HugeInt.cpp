#include "HugeInt.h"
#include <iostream>
#include <cmath>

/* convert string to vector of integers */
HugeInt::HugeInt(const std::string value)
{
    int counter;

    int vec_len = value.size() / NODE_LEN;
    for (int i = 0; i < vec_len; ++i)
    {
        int temp_num;
        int indx = value.size() - NODE_LEN * (i + 1);
        temp_num = stoi(value.substr(indx, 9));
        Int.insert(Int.begin(), temp_num);
    }
    if (value.size() % NODE_LEN)
    {
        int temp_num;
        temp_num = stoi(value.substr(0, value.size() - vec_len * NODE_LEN));
        Int.insert(Int.begin(), temp_num);
    }
}

HugeInt::HugeInt(int value)
{
    Int.insert(Int.begin(), value % (int)pow(10, NODE_LEN));
    if (value > NODE_INT_MAX)
        Int.insert(Int.begin(), value / (int)pow(10, NODE_LEN));
}

HugeInt HugeInt::operator+ (const HugeInt & arg)
{
    int num1_len;
    int num2_len;
    int i;
    int buffer_int;

    HugeInt temp("0");
    buffer_int = 0;
    i = 0;
    num1_len = this->Int.size();
    num2_len = arg.Int.size();
    while (temp.Int.size())
        temp.Int.pop_back();
    while (num1_len > 0 && num2_len > 0)
    {
        int res;
        res = this->Int[num1_len - 1] + arg.Int[num2_len - 1] + buffer_int;
        if (res > NODE_INT_MAX)
        {
            temp.Int.insert(temp.Int.begin(), res % (int)pow(10, NODE_LEN));
            buffer_int = res / (int)pow(10, NODE_LEN);
        }
        else
        {
            temp.Int.insert(temp.Int.begin(), res);
            buffer_int = 0;
        }
        ++i;
        --num1_len;
        --num2_len;
    }
    while (num1_len)
    {
        temp.Int.insert(temp.Int.begin(), this->Int[num1_len - 1] + buffer_int);
        buffer_int = 0;
        --num1_len;
    }
    while (num2_len)
    {
        temp.Int.insert(temp.Int.begin(), arg.Int[num2_len - 1] + buffer_int);
        buffer_int = 0;
        --num2_len;
    }
    if (buffer_int)
        temp.Int.insert(temp.Int.begin(), buffer_int);
    return (temp);
}

HugeInt& HugeInt::operator=(HugeInt arg)
{
    this->Int = arg.Int;
    return (*this);
}

HugeInt HugeInt::operator* (const HugeInt & arg)
{
    int             i;
    long long int   buffer_int;
    int             num1_len;
    int             num2_len;

    num1_len = this->Int.size();
    num2_len = arg.Int.size();
    HugeInt res("0");
    HugeInt temp("0");
    for (int i = num1_len - 1; i >= 0; --i)
    {
        buffer_int = 0;
        while (temp.Int.size())
            temp.Int.pop_back();
        for (int j = num2_len - 1; j >= 0; --j)
        {
            buffer_int += (long long int)arg.Int[j] * (long long int)this->Int[i];
            temp.Int.insert(temp.Int.begin(), buffer_int % (int)pow(10, NODE_LEN));
            buffer_int = buffer_int / (int)pow(10, NODE_LEN);
        }
        if (buffer_int)
            temp.Int.insert(temp.Int.begin(), buffer_int);
        int counter = 0;
        while (counter < num1_len - i - 1)
        {
            temp.Int.push_back(0);
            ++counter;
        }
        res = res + temp;
    }
    return (res);
}

void HugeInt::printNum()
{
    for (auto it = Int.begin(); it != Int.end(); ++it)
    {
        if ((it - 1) != Int.end() && it != Int.begin() && *it < NODE_INT_MAX)
        {
            int num_len;
            if (*it == 0)
                num_len = 1;
            else     
                num_len = (int)(log10(*it) + 1);
            for (int i = 0; i < NODE_LEN - num_len; ++i)
                std::cout<<'0';
        }
        std::cout<<*it;
    }
    std::cout<<std::endl;
}