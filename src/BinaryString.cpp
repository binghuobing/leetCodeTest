#include "BinaryString.h"
#include <iostream>
BinaryString::BinaryString(string s ):
    str(s)
{
    //ctor
}

BinaryString::~BinaryString()
{
    //dtor
}

const string& BinaryString::getString() {
    return str;
}

string operator+ (BinaryString& lh, BinaryString& rh)
{
    string a(lh.str);
    string b(rh.str);

    string lng, sht;
    if (a.size() > b.size() )
    {
        lng = a;
        sht = b;
    }
    else
    {
        lng = b;
        sht = a;
    }

    int extra = 0;
    string::reverse_iterator ilng = lng.rbegin(), isht = sht.rbegin();
    for (  ;isht != sht.rend(); ++ilng, ++isht)
    {
        int vlng = *ilng - '0';
        int vsht = *isht - '0';
        int val = vlng + vsht + extra;
        *ilng = '0' + val % 2;
        extra = val / 2;
    }

    while(ilng != lng.rend()) {
        if (extra == 0)
            break;
        if (*ilng == '0') {
            *ilng = '1';
            extra = 0;
        } else {
            *ilng = '0';
            extra = 1;
        }
        ++ilng;
    }
    if (extra == 1) {
        lng.insert(lng.begin(), '1');
    }
    return lng;
}

void BinaryString::testOpPlus() {
    BinaryString a("110");
    BinaryString b ("110");
    std::cout << a + b << std::endl;
}
