#ifndef POLECENIA_H
#define POLECENIA_H

#include <iostream>

int toInt(std::string number)
{
    int result = 0;
    int sequence = 0;
    //zamien string na int
    while (sequence < number.size())
    {
        result = result*10 + ((int)(number[sequence])-48);
        sequence++;
    }
    return result;
}

#endif