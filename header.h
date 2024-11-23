#ifndef HEADER_H
#define HEADER_H

#endif //HEADER_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

void saveToFile(const std::string& filename, const std::vector<std::string>& data);

void loadFromFile(const std::string& filename, std::vector<std::string>& outData);

struct Book
{
    std::string Author;
    std::string Title;
    int Year;
};

void saveToFile(const std::string& filename, const std::vector<Book>& data);

void loadFromFile(const std::string& filename, std::vector<Book>& outData);

enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

// в качестве ключа - название группы
// в качестве значения - список студентов
using Groups = std::map<std::string, std::vector<Student>>;

void saveToFile(const std::string& filename, const Groups& groups);

void loadFromFile(const std::string& filename, const Groups& outGroups);