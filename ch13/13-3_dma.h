#include"13-3_abc.h"

class baseDMA : public AbcDMA{
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA(){};
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
    virtual void view();
};

// derived class without DMA
class lacksDMA : public AbcDMA{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const AbcDMA & abc);
    lacksDMA(const lacksDMA & la);
    virtual ~lacksDMA(){};
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & la);
    virtual void view();
};

// derived class with DMA
class hasDMA : public AbcDMA{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const AbcDMA & abc);
    hasDMA(const hasDMA & hs);
    virtual ~hasDMA();
    hasDMA & operator=(const hasDMA & hs);
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & hs);
    virtual void view();
};