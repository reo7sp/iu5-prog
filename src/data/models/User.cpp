#include "data/models/User.h"

#include "util/iterator-util.h"

User::User() = default;

User::User(std::string name) : _name(std::move(name)) {
}

std::string User::getName() const {
    return this->_name;
}

bool User::addOwnedBook(Book book) {
    return this->_ownedBooks.add(book.getSubject(), book);
}

bool User::removeOwnedBook(const Book& book) {
    return this->_ownedBooks.remove(book.getSubject(), book);
}

bool User::hasOwnedBook(const Book& book) const {
    return this->_ownedBooks.has(book.getSubject(), book);
}

bool User::hasOwnedBookWithSubject(const Subject& subject) const {
    return this->_ownedBooks.has(subject);
}

User::BookIterator User::ownedBooksBegin() const {
    return BookIterator(this->_ownedBooks.begin());
}

User::BookIterator User::ownedBooksEnd() const {
    return BookIterator(this->_ownedBooks.end());
}

size_t User::ownedBooksCount() const {
    return this->_ownedBooks.count();
}

bool User::operator<(const User& other) const {
    if (this->getName() != other.getName()) {
        return this->getName() < other.getName();
    }
    return false;
}

bool User::operator==(const User& other) const {
    return this->getName() == other.getName();
}

bool User::operator!=(const User& other) const {
    return !(*this == other);
}


