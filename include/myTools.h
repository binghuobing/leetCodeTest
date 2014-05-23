#ifndef MY_TOOLS_H
#define MY_TOOLS_H


#include <vector>
#include <iostream>
#include "TreeNode.h"

void printDoubleVector( const std::vector<std::vector<int> > &dvec);

int * createIntArray(int& n) ;

template<class T>                             // ģ�庯���Ķ���������ͷ�ļ��У���include����
void printContainer(const T& container)
{
    size_t size = container.size();
    for (size_t i = 0; i != size; ++i)
    {
        std::cout << container[i] << "\t";
    }
    std::cout << std::endl;
}

#endif // MY_TOOLS_H
