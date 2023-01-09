#include"13-4_port.h"

class VintagePort : public Port{
    // style necessarily = "Vintage"
private:
    char * nickname;        // i.e., "The Noble" or "Old Velvet", etc.
    int year;               // vintage year
public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() { delete [] nickname; }
    VintagePort & operator=(const VintagePort & vp);
    void show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & vp);
};