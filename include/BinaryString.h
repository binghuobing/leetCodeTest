#ifndef BINARYSTRING_H
#define BINARYSTRING_H
#include<string>

using std::string;
class BinaryString
{
    public:
        explicit BinaryString(string s = "");
        virtual ~BinaryString();
        const string& getString();
        friend string operator+(BinaryString& a, BinaryString& b);
        void testOpPlus();
    protected:
    private:
        string str;
};

#endif // BINARYSTRING_H
