
#include <data/models/Book.h>
#include <data/serializers/book.h>


#include "data/models/Book.h"

Book::Book() = default;

Book::Book(std::string name, Subject subject) : _name(std::move(name)), _subject(std::move(subject)) {
}

std::string Book::getName() const {
    return this->_name;
}

Subject Book::getSubject() const {
    return this->_subject;
}

bool Book::operator<(const Book& other) const {
    if (this->_name != other._name) {
        return this->_name < other._name;
    }
    return false;
}

bool Book::operator==(const Book& other) const {
    return this->_name == other._name;
}

bool Book::operator!=(const Book& other) const {
    return !(*this == other);
}


