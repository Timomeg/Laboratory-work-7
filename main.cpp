#include "header.h"
int main() {
    std::ofstream out;
    out.open("lol.txt", std::ios::app);
    const std::vector<std::string> str= {"daadasd", "dasdas"};
    saveToFile("lol.txt", str);
    out.close();
    return 0;
}
