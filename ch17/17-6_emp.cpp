#include"17-6_emp.h"
#include <fstream>
#include <ostream>
#include <string>

// ab_emp methods
ab_emp::ab_emp() {
    fname = "none";
    lname = "none";
    job = "none";
}

ab_emp::ab_emp(const std::string & fn, const std::string & ln,
               const std::string & j) : fname(fn), lname(ln), job(j)
{
}

ab_emp::~ab_emp() {}


void ab_emp::ShowAll() const {
    std::cout << "firstname: " << fname << std::endl;
    std::cout << "lastname: " << lname << std::endl;
    std::cout << "job: " << job << std::endl;
}

void ab_emp::SetAll() {
    std::cout << "Enter firstname: ";
    std::getline(std::cin, fname);
    std::cout << "Enter lastname: ";
    std::getline(std::cin, lname);
    std::cout << "Enter job: ";
    std::getline(std::cin, job);
}

std::ofstream & ab_emp::WriteAll (std::ofstream &of) const{
    of << fname << " " << lname << " " << job;
    return of;
}

std::ostream & operator<<(std::ostream & os, const ab_emp & e){
    os << e.fname << " " << e.lname << " " << e.job;
    return os;
}


// employee methods
employee::employee(){}

employee::employee(const std::string & fn, const std::string & ln,
                const std::string & j): ab_emp(fn, ln, j)
{

}

void employee::ShowAll() const {
    ab_emp::ShowAll();
}

void employee::SetAll() {
    ab_emp::SetAll();
}

std::ofstream & employee::WriteAll(std::ofstream &of) const {
    of << Employee << " ";
    ab_emp::WriteAll(of);
    return of;
}


// manager methods
manager::manager() {
    inchargeof = 0;
}

manager::manager(const std::string & fn, const std::string & ln,
                 const std::string & job, int ico)
                 : ab_emp(fn, ln, job), inchargeof(ico)
{
}

manager::manager(const ab_emp & e, int ico) : ab_emp(e), inchargeof(ico) {

}

manager::manager(const manager & m) : ab_emp(m), inchargeof(m.inchargeof){

}

void manager::ShowAll() const {
    ab_emp::ShowAll();
    std::cout << "InchargeOf: " << inchargeof << std::endl;
}

void manager::SetAll() {
    ab_emp::SetAll();
    std::cout << "Enter inchargeof: ";
    std::cin >> inchargeof;
    std::cin.get();
}

std::ofstream & manager::WriteAll(std::ofstream &of) const {
    of << Manager << " ";
    ab_emp::WriteAll(of) << " " << inchargeof;
    return of;
}

// fink methods
fink::fink() {
    reportsto = "none";
}

fink::fink(const std::string & fn, const std::string ln,
           const std::string & job, const std::string repo) 
           : ab_emp(fn,ln,job), reportsto(repo)
{

}

fink::fink(const ab_emp & e, const std::string repo)
        : ab_emp(e), reportsto(repo)
{

}

fink::fink(const fink & f)
    : ab_emp(f) ,reportsto(f.reportsto)
{
}

void fink::ShowAll() const
{
    ab_emp::ShowAll();
    std::cout << "Reportsto: " << reportsto << std::endl;
}

void fink::SetAll()
{
    ab_emp::SetAll();
    std::cout << "Enter reportsto: ";
    std::getline(std::cin, reportsto);
}

std::ofstream & fink::WriteAll(std::ofstream & fout) const
{
    fout << Fink << " ";
    ab_emp::WriteAll(fout)<< " " << reportsto;
    return fout;
}


// highfink methods
highfink::highfink(){}

highfink::highfink(const std::string & fn, const std::string & ln,
                    const std::string & j, const std::string & repo, int ico)
                : ab_emp(fn,ln,j), manager(fn,ln,j,ico), fink(fn,ln,j, repo)
{

}

highfink::highfink(const ab_emp & e, const std::string & repo, int ico)
                : ab_emp(e), manager(e,ico), fink(e,repo)
{

}

highfink::highfink(const fink & f, int ico)
                : ab_emp(f), fink(f), manager((const ab_emp &)f, ico)
{

}

highfink::highfink(const manager & m, const std::string & repo)
                : ab_emp(m), manager(m), fink((const ab_emp &)m, repo)
{

}

highfink::highfink(const highfink & h)
                : ab_emp(h), manager(h), fink(h)
{

}

void highfink::ShowAll() const {
    ab_emp::ShowAll();
    
    std::cout << "ReportsTo: " << fink::ReportsTo() << std::endl;
    std::cout << "Inchargeof: "<< manager::InChargeOf() << std::endl;
}

void highfink::SetAll() {
    ab_emp::SetAll();
    std::cout << "Enter reportsto: ";
    std::getline(std::cin, fink::ReportsTo());
    std::cout << "Enter inchargeof: ";
    std::cin>>manager::InChargeOf();
    std::cin.get();
}

std::ofstream & highfink::WriteAll(std::ofstream &fout) const {
    fout << Highfink << " ";
    ab_emp::WriteAll(fout) << " " << fink::ReportsTo() << " " << manager::InChargeOf();
    return fout;
}