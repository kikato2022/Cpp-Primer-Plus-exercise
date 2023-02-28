//#include <cstdlib>
#include<fstream>
#include<iostream>
#include<string>



int main(int argc, char* argv[]){
    if(argc!=3){
        std::cout << "Usage: "  << argv[0] << " <target filename>  <sourse filename>.\n";
        exit(EXIT_FAILURE);
    }
    std::ofstream ofs;
    ofs.open(argv[1], std::ios_base::out);
    if(!ofs.is_open()){
        std::cerr << "Error happen when open " << argv[1] << ".\n";
        exit(EXIT_FAILURE);
    }
    std::ifstream ifs;
    ifs.open(argv[2], std::ios_base::in);
    if(!ifs.is_open()){
        std::cerr << "Error happen when open " << argv[2] << ".\n";
        exit(EXIT_FAILURE);
    }
    std::string line;
    getline(ifs,line);
    while(line.size()>0){
        ofs << line << std::endl;
        getline(ifs,line);
    }
    if(!ifs.eof()){
        std::cerr << "Error happens when read " << argv[1] << ".\n";
    }

    return 0;
}