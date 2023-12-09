#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>

template <class Type>
class Reader{
    public:
        Reader(){

        }
        Type convertTo(const std::string& str){
            std::istringstream ss(str);
            Type converted;
            ss >> converted;
            return converted;
        }
        std::vector<Type> ReadFile(std::string fileName){
            std::vector<Type> output;
            fin.open(fileName);
            std::string c;
            fin >> c;
            while (c.find(' ') != -1){
                output.push_back(convertTo(c.substr(0, c.find(' '))));
                c = c.substr(c.find(' ') + 1, c.size() - c.find(' ') - 1);
            }
            fin.close();
            return output;
        }
        void Write(std::string fileName, std::vector<Type> alphabet, std::vector<std::vector<Type>> listPattern, std::vector<std::map<Type, size_t>> table){
            fout.open("output/output_" + fileName);
            fout << "num\tprefix\t";
            for (size_t i = 0; i < alphabet.size(); i++){
                fout << alphabet[i] << '\t';
            }
            fout << '\n';
            for (size_t i = 0; i < table.size(); i++){
                fout << i << " :\t";
                for (size_t j = 0; j < listPattern[i].size(); j++){
                    fout << listPattern[i][j];
                }
                fout << '\t';
                for (size_t j = 0; j < alphabet.size(); j++){
                    fout << table[i][alphabet[j]] << '\t';
                }
                fout << '\n';
            }
            fout.close();
        }
    private:
        std::ifstream fin;
        std::ofstream fout;
};
