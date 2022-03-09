#ifndef HUGEINT_H
# define HUGEINT_H

#include <string>
#include <vector>

using std::vector;

class HugeInt
{
public:
     HugeInt(const std::string value);
     HugeInt(int value);
     HugeInt operator + (const HugeInt & arg);
     HugeInt operator * (const HugeInt & arg);
     HugeInt& operator= (HugeInt arg);
     void printNum();
private:
     vector<int> Int;
     const int NODE_INT_MAX = 999999999;
     const int NODE_LEN = 9;
};

#endif
