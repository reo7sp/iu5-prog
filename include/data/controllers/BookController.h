#ifndef IU5_PROG_BOOKCONTROLLER_H
#define IU5_PROG_BOOKCONTROLLER_H

#include <string>
#include "data/models/Books.h"
#include "data/models/Book.h"

class DataStore;

class BookController {
public:
    explicit BookController(DataStore& store);

    bool addBookWithNameAndSubjectName(std::string name, std::string subjectName);
    bool removeBookWithName(const std::string& name);
    bool giveBookWithNameToUserWithName(const std::string& bookName, const std::string& userName);
    bool returnBookWithNameFromUserWithName(const std::string& bookName, const std::string& userName);
    Books::BookIterator booksBegin() const;
    Books::BookIterator booksEnd() const;

private:
    DataStore& _store;
};

#endif //IU5_PROG_BOOKCONTROLLER_H
