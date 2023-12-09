#include "reader.h"
#include "fsm.h"
#include <string>

int main(){
    Reader<std::string> reader1;
    std::vector<std::string> text1 = reader1.ReadFile("samples/text1.txt");
    std::vector<std::string> pattern1 = reader1.ReadFile("samples/pattern1.txt");
    Fsm<std::string> fsm1(pattern1);
    reader1.Write("text1.txt", fsm1.GetAlphabet(), fsm1.GetListPattern(), fsm1.GetTable());
    fsm1.FindSubstr(text1);
    std::cout << "Count of intersecting substrings: " << fsm1.GetCountSubstr() << '\n';
    return 0;
}
