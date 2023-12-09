#include "reader.h"


template <>
std::vector<std::string> Reader<std::string>::ReadFile(std::string fileName){
    std::vector<std::string> output;
    fin.open(fileName);
    std::string c;
    fin >> c;
    for (size_t i = 0; i < c.size(); i++){
        output.push_back(std::string{c[i]});
    }
    fin.close();
    std::cout << "Complete read from file: " << fileName << '\n';
    return output;
}
