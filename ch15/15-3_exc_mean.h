#include<iostream>
#include <stdexcept>


class bad_mean : public std::logic_error{
public:
    double v1, v2;
    bad_mean(const char *s, double a = 0, double b = 0) 
        : v1(a), v2(b), logic_error(s) {}
    virtual void mesg(){
        std::cout << "func: " << what() << std::endl;
        std::cout << "arguments: " << v1 << ", " << v2 << ". \n";
    }
};


class bad_hmean : public bad_mean {

public:
	bad_hmean(const char * s, double a = 0, double b = 0) : bad_mean(s,a,b) {}
	void mesg();
};

inline void bad_hmean::mesg(){
    bad_mean::mesg();
	std::cout << "invalid arguments: a = -b\n";       
}



class bad_gmean : public bad_mean{
public:
    bad_gmean(const char * s,  double a = 0, double b = 0) : bad_mean(s,a,b) {}
    void mesg();
};

inline void bad_gmean::mesg(){
    bad_mean::mesg();
    std::cout << "gmean() arguments should be >= 0\n";
}