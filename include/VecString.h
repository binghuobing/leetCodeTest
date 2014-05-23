#ifndef VECSTRING_H
#define VECSTRING_H
#include <vector>
#include<string>

using std::vector;
using std::string;

class VecString
{
    public:
        VecString();
        VecString(vector<string> vec);
        virtual ~VecString();
        string longestCommonPrefix();
        void testComomPrefix();
    protected:
    private:
        vector<string> vec;
};

#endif // VECSTRING_H
