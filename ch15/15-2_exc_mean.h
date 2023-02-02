#include<iostream>
#include<stdexcept>


class bad_hmean : public std::logic_error{

public:
	bad_hmean( const char * s) : logic_error(s) {}
	//void mesg();
};

// inline void bad_hmean::mesg(){
// 	std::cout << "hmean(" << v1 << ", " << v2 << "): "
//               << "invalid arguments: a = -b\n";       
// }



class bad_gmean: public std::logic_error{
public:
    // double v1;
    // double v2;
    bad_gmean(const char * s) : logic_error(s){}
    //const char * mesg();
};

// inline const char * bad_gmean::mesg(){
//     return "gmean() arguments should be >= 0\n";
// }