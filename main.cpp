#include "suffixautomaton.h"


int main(){
    std::cout << "first sample:\n";
    std::vector<char> s = {'a', 'b', 'c', 'b', 'c'};
    std::vector<char> w = {'a', 'b', 'c'};
    SuffixAutomaton<char> suffAuto(s);
    suffAuto.IsSubstr(w);

    std::cout << "second sample:\n";
    std::vector<int> s1 = {1, 2, 3, 1, 2, 4, 1, 3, 1, 2};
    std::vector<int> w1 = {1, 2};
    SuffixAutomaton<int> suffAuto1(s1);
    suffAuto1.IsSubstr(w1);

    return 0;
}
