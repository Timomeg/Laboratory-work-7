#include "header.h"

void saveToFile(const std::string& filename, const Groups& groups) {
    std::ofstream out;

    out.open(filename, std::ios::app);
    for (const auto& group: groups) {
        out << group.first;
        for (const auto& student: group.second) {
            out << '\n' << student.Name << " " << student.Year << '\n';
            for (const auto& score: student.RecordBook) {
                out << score.first << ":" << score.second << " ";
            }
        }
        out << '\n' <<"-"<< '\n';
    }
    out.close();
}

void loadFromFile(const std::string& filename, Groups& outGroups) {
    int count{};
    std::string group_name;
    std::string student_name;
    std::string subject;
    std::string subject_score;
    std::ifstream in;
    std::string age;
    Student student;
    std::map<std::string, Score> score_book;
    std::vector<Student> student_list;

    std::map<std::string,Score> scores;
    scores["2"] = Unsatisfactorily;
    scores["3"] = Satisfactorily;
    scores["4"] = Good;
    scores["5"] = Excellent;

    in.open(filename, std::ios::in);
    if (in.is_open()) {
        std::string line;

        while(std::getline(in, line)) {

            count ++;
            if (count == 1) {
                group_name = line;
            }
            if (count > 1 && count % 2 == 0) {
                for (auto character: line) {

                    if (isalpha(character)) {
                        student_name += character;
                    }
                    if (isdigit(character)) {
                        age += character;
                    }
                }
            }
            if (count > 1 && count % 2 == 1) {
                for(auto elem: line) {
                    if (isalpha(elem)) {
                        subject += elem;
                    }
                    if (isdigit(elem)) {
                        subject_score += elem;
                    }
                    if (elem == ' ') {
                        score_book[subject] = scores[subject_score];
                        subject = "";
                        subject_score = "";
                    }
                }
                student.Name = student_name;
                student.Year = stoi(age);
                student.RecordBook = score_book;
                student_list.push_back(student);

                student_name = "";
                age = "";
                score_book.clear();
            }
            if (line == "-") {
                outGroups[group_name] = student_list;
                count = 0;
                student_list.clear();
            }
        }
        in.close();

    }
}