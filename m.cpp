#include <iostream>
#include <vector>
#include "Matrix/Matrix.hpp"

std::vector<std::vector<int> > as={{1,2,3},{1,2}};

int main()
{
    zvlib::Matrix mtrx;
    for(std::vector<int> v : mtrx.Add(as,as))
    {
        std::cout<<v[0];
    }
    //std::cout<<as[0].size();
}
