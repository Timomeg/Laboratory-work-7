#include "header.h"

void saveToFile(const std::string& filename, const std::vector<Book>& data) {
    std::ofstream out;
    out.open(filename, std::ios::app);
    for (const auto& str: data) {
        //out << str << std::endl;
    }
    out.close();
}

void loadFromFile(const std::string& filename, std::vector<Book>& outData) {
    std::ifstream in;
    std::string line;

    in.open(filename, std::ios::in);
    while(std::getline(in, line)) {
        //outData.push_back(line);
    }
    in.close();

}