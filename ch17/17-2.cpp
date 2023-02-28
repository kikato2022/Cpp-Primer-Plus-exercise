#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]){
    if(argc<2){
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::fstream fs;
    for(int file = 1; file < argc; file++){
        fs.open(argv[file], std::ios_base::out);
        if(!fs.is_open()){
            std::cerr << "error happens when open " << argv[file] << ".\n";
            exit(EXIT_FAILURE);
        }
        std::cout << "Please enter your input: \n";
        std::string input;
        getline(std::cin, input);
        while(input.size()>0){
            fs << input << std::endl;
            getline(std::cin, input);
        }
        fs.clear();
        fs.close();

        
        fs.open(argv[file], std::ios_base::in); 
        if(!fs.is_open()){
            std::cerr << "error happens when open " << argv[file] << ".\n";
            exit(EXIT_FAILURE);
        }
        std::cout << "The content of the " << argv[file] << ":\n";

        char ch;
        while(fs.get(ch)){
            std::cout << ch;
        }
        if(!fs.eof()){
            std::cerr << "error happens when read " << argv[file] << ".\n";
            exit(EXIT_FAILURE);
        }

        return 0;
    }



}