#include "header.h"

void saveToFile(const std::string& filename, const std::vector<std::string>& data) {
    std::ofstream out;
    out.open(filename, std::ios::app);
    if (out.is_open()) {
        for (const auto& str: data) {
            out << str << std::endl;
        }
    }
    out.close();
}

void loadFromFile(const std::string& filename, std::vector<std::string>& outData) {
    std::ifstream in;
    std::string line;

    in.open(filename, std::ios::in);
    if (in.is_open()) {
        while(std::getline(in, line)) {
            outData.push_back(line);
        }
    }
    in.close();

}