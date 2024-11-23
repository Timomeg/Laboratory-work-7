#include "header.h"

void saveToFile(const std::string& filename, const std::vector<Book>& data) {
    std::ofstream out;
    out.open(filename, std::ios::app);
    if (out.is_open()) {
        for (const auto& book: data) {
            out << book.Author << "\n";
            out << book.Title << "\n";
            out << book.Year << std::endl;
        }
    }
    out.close();
}

void loadFromFile(const std::string& filename, std::vector<Book>& outData) {
    std::ifstream in;
    std::string line;
    int i{};
    std::string author;
    std::string title;
    int year{0};

    in.open(filename, std::ios::in);
    if (in.is_open()) {
        while(std::getline(in, line)) {
            if (i % 3 == 0) {
                author = line;
            }
            if (i % 3 == 1) {
                title = line;
            }
            if (i % 3 == 2) {
                for (auto j: line) {
                    year = year * 10 + static_cast<int>(j);
                }
                Book book_i{author, title, year};
                outData.push_back(book_i);
            }
            i++;
        }
    }
    in.close();

}