#ifndef EMP_H_
#define EMP_H_

#include<iostream>
#include<fstream>
#include<string>


enum classkind {Employee, Manager, Fink, Highfink}; // in class header

class ab_emp {;
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    ab_emp();
    ab_emp(const std::string & fn, const std::string & ln,
           const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual std::ofstream & WriteAll(std::ofstream & of) const;
    friend std::ostream & operator<<(std::ostream & os, const ab_emp & e);
    virtual ~ab_emp() = 0;
};


class employee : virtual public ab_emp {
public:
    employee();
    employee(const std::string & fn, const std::string & ln,
             const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream & WriteAll(std::ofstream & of) const;
};


class manager : virtual public ab_emp {
private:
    int inchargeof;
protected:
    int InChargeOf() const {return inchargeof;}
    int & InChargeOf() {return inchargeof;}
public:
    manager();
    manager(const std::string & fn, const std::string & ln,
            const std::string & j, int ico = 0);
    manager(const ab_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream & WriteAll(std::ofstream & of) const;
};

class fink : virtual public ab_emp {
private:
    std::string reportsto;
protected:
    std::string ReportsTo() const { return reportsto;}
    std::string & ReportsTo() {return reportsto;}
public:
    fink();
    fink(const std::string & fn, const std::string ln,
         const std::string & j, const std::string repo);
    fink(const ab_emp & e, const std::string repo);
    fink(const fink & f);
    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream & WriteAll(std::ofstream & of) const; 
};

class highfink : public manager, public fink {
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico);
    highfink(const ab_emp & e, const std::string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
    std::ofstream & WriteAll(std::ofstream & fout) const;
};




#endif