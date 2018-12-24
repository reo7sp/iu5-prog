#ifndef IU5_PROG_BOOK_H
#define IU5_PROG_BOOK_H

#include <string>
#include "Subject.h"

class Book {
public:
    Book();
    Book(std::string name, Subject subject);

    std::string getName() const;
    Subject getSubject() const;

    bool operator<(const Book& other) const;
    bool operator==(const Book& other) const;
    bool operator!=(const Book& other) const;

private:
    std::string _name;
    Subject _subject;
};

#endif //IU5_PROG_BOOK_H
