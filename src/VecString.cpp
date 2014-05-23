#include "VecString.h"
#include <iostream>

VecString::VecString()
{
}

VecString::VecString(vector<string> v) : vec(v)
{
}

VecString::~VecString()
{
}

string VecString::longestCommonPrefix()
{
    if (vec.empty())
        return string();
    typedef vector<string>::size_type vSizeType;
    typedef string::size_type sSizeType;

    vSizeType vecLen = vec.size();
    sSizeType minLen = vec[0].size();
    for (vSizeType i = 0; i < vecLen; ++i) {
        if(vec[i].size() < minLen)
            minLen = vec[i].size();
    }

    for (sSizeType i = 0; i <= minLen; ++i) {
        char c = vec[0][i];
        for (vSizeType j = 1; j < vecLen; j++) {
            if(vec[j][i] != c) {
                return vec[0].substr(0, i);
            }
        }
    }
    return vec[0];
}

void VecString::testComomPrefix()
{
    string s1("abc");
    string s2("abcde");
    string s3("bcbd");
    vector<string> vec;
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);
    VecString vs(vec);
    std::cout << vs.longestCommonPrefix() << std::endl;
}
