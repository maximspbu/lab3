#pragma once
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

template <class Type>
class Fsm{
    public:
        Fsm(std::vector<Type> pattern_):pattern(pattern_){
            MakeAlphabet();
            MakeListPattern();
            MakeTable();
        };
        void MakeAlphabet(){
            for (size_t i = 0; i < pattern.size(); i++){
                if (std::find(alphabet.begin(), alphabet.end(), pattern[i]) == alphabet.end()){
                    alphabet.push_back(pattern[i]);
                }
            }
            std::sort(alphabet.begin(), alphabet.end());
            std::cout << "Complete making alphabet\n";
        }
        void MakeListPattern(){
            for (size_t i = 0; i < pattern.size()+1; i++){
                std::vector<Type> listPat;
                for (size_t j = 0; j < i; j++){
                    listPat.push_back(pattern[j]);
                }
                listPattern.push_back(listPat);
            }
            std::cout << "Complete making list of patterns\n";
        }
        void MakeTable(){
            for (int i = 0; i < pattern.size()+1; i++){
                std::map<Type, size_t> localTable;
                table.push_back(localTable);
                for (size_t j = 0; j < alphabet.size(); j++){
                    table[i][alphabet[j]] = 0;
                    if ((alphabet[j] == pattern[i])){
                        table[i][alphabet[j]] = i + 1;
                    } else {
                        ind = 0;
                        std::vector<Type> newPattern = listPattern[i];
                        newPattern.push_back(alphabet[j]);
                        for (int prev = i; prev > 0; prev--){
                            complete = true;
                            for (int c = 0; c < listPattern[prev].size(); c++){
                                if (listPattern[prev][c] != newPattern[c + (i - prev) + 1]){
                                    complete = false;
                                    break;
                                }
                                ind = prev;
                            }
                            if (complete){
                                table[i][alphabet[j]] = ind;
                                break;
                            }
                        }
                    }
                }
            }
            std::cout << "Complete making table\n";
        }
        void FindSubstr(std::vector<Type> text){
            size_t i = 0;
            size_t pos = 0;
            while (i < text.size()){
                pos = table[pos][text[i]];
                if (pos == pattern.size()) countSubstr++;
                i++;
            }
        }
        std::vector<Type> GetAlphabet(){
            return alphabet;
        }
        std::vector<std::vector<Type>> GetListPattern(){
            return listPattern;
        }
        std::vector<std::map<Type, size_t>> GetTable(){
            return table;
        }
        size_t GetCountSubstr(){
            return countSubstr;
        }
    private:
        std::vector<Type> alphabet;
        std::vector<Type> pattern;
        bool complete;
        size_t ind;
        size_t countSubstr = 0;
        std::vector<std::vector<Type>> listPattern;
        std::vector<std::map<Type, size_t>> table;
};
