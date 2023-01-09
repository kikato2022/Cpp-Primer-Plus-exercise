// Abstract base class

#ifndef ABC_H_
#define ABC_H_

#include<iostream>

class AbcDMA{
private:
    char * label;
    int rating;
public:
    AbcDMA(const char * l = "null", int r = 0);
    AbcDMA(const AbcDMA & abc);
    virtual ~AbcDMA()=0;
    AbcDMA & operator=(const AbcDMA & abc);
    friend std::ostream & operator<<(std::ostream & os, const AbcDMA & abc);
    virtual void view() = 0;
};

#endif