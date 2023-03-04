#include<string>
#include<iostream>

class Cpmv {
public:
    struct Info {
        std::string qcode;
        std::string zcode;
    };
private:
    Info *pi;
public:
    Cpmv();
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv & cp);
    Cpmv(Cpmv && mv);
    ~Cpmv();
    Cpmv & operator=(const Cpmv & cp);
    Cpmv & operator=(Cpmv && mv);
    Cpmv operator+(const Cpmv & obj) const;
    void Display() const;
};

Cpmv::Cpmv() {
    std::cout << "default constructer" << std::endl;
    pi = new Info;
    pi->qcode = "null";
    pi->zcode = "null";
}

Cpmv::Cpmv(std::string q, std::string z){
    std::cout << "constructer" << std::endl;
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv & cp){
    std::cout << "copy constructer" << std::endl;
    pi = new Info(*cp.pi);
}

Cpmv::Cpmv(Cpmv && mv){
    std::cout << "move constructor" << std::endl;
    pi = mv.pi;
    mv.pi = nullptr;
}

Cpmv::~Cpmv() {
    std::cout << "destructor" << std::endl;
    delete pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp) {
    std::cout << "assigment" << std::endl;
    if(this == &cp){
        return *this;
    }
    delete pi;
    pi = new Info(*cp.pi);
    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv) {
    std::cout << "move assignment" << std::endl;
    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const {
    std::cout << "operator+" << std::endl;
    Cpmv c;
    c.pi->qcode = pi->qcode + obj.pi->qcode;
    c.pi->zcode = pi->zcode + obj.pi->zcode;
    return c;
}

void Cpmv::Display() const {
    std::cout << pi->qcode << " " << pi->zcode << std::endl;
}

int main(){
    {
        Cpmv c1;
        c1.Display();
        Cpmv c2("c2c2c2", "2c2c2c");
        c2.Display();
        Cpmv c3("c3c3c3", "c3c3c3");
        c3.Display();
        Cpmv c4(c3);
        c4.Display();
        Cpmv c5(c2+c3);
        c5.Display();
        c1 = c5;
        c1.Display();
        c1 = c5+c5;
        c1.Display();
    }

    return 0;
}