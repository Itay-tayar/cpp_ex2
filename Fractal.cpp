#include "Fractal.h"
#include <math.h>
#include <iostream>

Fractal::Fractal(int dim): _dim (dim), frac(pow(3, _dim))
{
    for (int i = 0; i < pow(3, _dim); ++i)
    {
        frac[i].resize(pow(3, _dim));
    }

}


//SierpinskiCarpet

SierpinskiCarpet::SierpinskiCarpet(int dim): Fractal(dim)
{
}

char SierpinskiCarpet::isFill(int x, int y)
{
    while (x > 0 || y > 0) // when either of these reaches zero the pixel is determined to be on the edge
        // at that square level and must be filled
    {
        if (x % 3 == 1 && y % 3 == 1) //checks if the pixel is in the center for the current square level
            return ' ';
        x /= 3; //x and y are decremented to check the next larger square level
        y /= 3;
    }
    return '#'; // if all possible square levels are checked and the pixel is not determined
    // to be open it must be filled
}

void SierpinskiCarpet::createFrac()
{
    int length = pow(3, _dim);
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            frac[i][j] = isFill(i,j);
        }
    }
}

void SierpinskiCarpet::doDraw()
{
    createFrac();
    int length = pow(3, _dim);
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            std::cout<<frac[i][j];
        }
        std::cout<<std::endl;
    }
}