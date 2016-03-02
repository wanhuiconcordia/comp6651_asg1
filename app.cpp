#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include "repeat_once.h"


int main(int argc, char** argv){
    std::string inputFileName = "sample.txt";
    if(argc > 1){
        inputFileName = argv[1];
    }
    std::cout << "read from:" << inputFileName << std::endl;
    std::ifstream input(inputFileName);
    if(input.is_open()){
        std::vector<std::string> lines;
        std::string line;
        while(std::getline(input, line)){
            lines.push_back(line);
        }
        input.close();

        auto start = std::chrono::steady_clock::now();
        int n = 0;
        for(auto str: lines){
            if(str.length() > 0){
                int nn = repeat_once(str);
                std::cout << "Found " << nn << " repeat-once sub-string in " << str << " (string length: " <<  str.length() << ")" << std::endl;
                n += nn;
            }
        }
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
        std::cout << "Total " << n << " repeat-once sub-string in file:" << inputFileName << std::endl;
        std::cout << "Spent " << duration << " milliseconds" << std::endl;
    }else{
        std::cout << "Cannot open " << inputFileName << std::endl;
    }

    return 0;
}
