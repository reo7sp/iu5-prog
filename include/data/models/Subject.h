#include <utility>

#include <utility>

#ifndef IU5_PROG_SUBJECT_H
#define IU5_PROG_SUBJECT_H

#include <string>

class Subject {
public:
    Subject();
    explicit Subject(std::string name);

    std::string getName() const;

    bool operator<(const Subject& other) const;
    bool operator==(const Subject& other) const;
    bool operator!=(const Subject& other) const;

private:
    std::string _name;
};

#endif //IU5_PROG_SUBJECT_H
