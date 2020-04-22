#ifndef H_3_3_H
#define H_3_3_H

#include <cassert>
#include <iostream>
#include <fstream>

void implicit_Euler(int n)
{
    assert(n>1);
    float h = (float) 1 / (float) n;
    float step = (float) 1/float(h+1);
    float x =0;
    float y= 1;
    std ::cout << "h=" << h ;
    std ::ofstream write_file("xy.dat");
    assert(write_file.is_open());

    while (x < 1)
    {
        write_file << x << "," << y << "\n";
        y = step * y;
        x +=h;
    }
}
#endif
