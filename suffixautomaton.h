#pragma once
#include "state.h"
#include <vector>
#include <map>
#include <iostream>


template <class Type>
class SuffixAutomaton{
    private:
        class State{
            public:
                int link;
                size_t len;
                std::map<Type, size_t> next;
                State(int link_, size_t len_, std::map<Type, size_t> next_): link(link_), len(len_), next(next_){}
        };
        int last;
        std::vector<State> states;
        std::vector<Type> str;
    public:
        SuffixAutomaton(std::vector<Type> str_) : str(str_){
            states.emplace_back(-1, 0, std::map<Type, size_t>());
            last = 0;
            for (size_t i = 0; i < str_.size(); i++){
                Add(str_[i]);
            }
        }
        void Add(Type c){
            size_t r = states.size() - 1;
            states.emplace_back(0, r+1, std::map<Type, size_t>());
            int p = last;
            while ((p>=0) && (states[p].next.find(c) == states[p].next.end())){
                states[p].next[c] = r;
                p = states[p].link;
            }
            if (p != -1){
                size_t q = states[p].next[c];
                if (states[p].len == states[q].len + 1){
                    states[r].link = q;
                } else {
                    states.emplace_back(states[q].link, states[p].len + 1, states[q].next);
                    int qq = states.size() - 1;
                    states[q].link = qq;
                    states[r].link = qq;
                    while ((p>=0) && (states[p].next[c] == q)){
                        states[p].next[c] = qq;
                        p = states[p].link;
                    }
                }
            }
            last = r;
        }
        void IsSubstr(std::vector<Type> substr){
            bool complete = true;
            int n = 0;
            for (size_t i = 0; i < substr.size(); i++){
                if (states[n].next.find(substr[i]) == states[n].next.end()){
                    complete = false;
                    break;
                }
                n = states[n].next[substr[i]];
            }
            for (size_t i = 0; i < substr.size(); i++){
                std::cout << substr[i];
            }
            if (complete) std::cout << " is a substring of ";
            else std::cout << " is not a substring of ";
            for (size_t i = 0; i < str.size(); i++){
                std::cout << str[i];
            }
            std::cout << '\n';
        }
};
