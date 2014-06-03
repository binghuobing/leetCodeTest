#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<vector>

class Sequence
{
    public:
        Sequence();
        Sequence(std::vector<int> );
        virtual ~Sequence();

        int getLongestConsecutive();
    protected:
    private:
        std::vector<int> data;

};

#endif // SEQUENCE_H
