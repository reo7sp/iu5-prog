#include <utility>

#include <utility>
#include <data/controllers/BookController.h>


#include "data/controllers/BookController.h"
#include "data/DataStore.h"

BookController::BookController(DataStore& store) : _store(store) {
}

bool BookController::addBookWithNameAndSubjectName(std::string name, std::string subjectName) {
    return this->_store._books.addBook(Book(std::move(name), Subject(std::move(subjectName))));
}

bool BookController::removeBookWithName(const std::string& name) {
    return this->_store._books.removeBookWithName(name);
}

bool BookController::giveBookWithNameToUserWithName(const std::string& bookName, const std::string& userName) {
    User* user = this->_store._users.getUserWithName(userName);
    if (user == nullptr) {
        return false;
    }

    const Book* book = this->_store._books.getBookWithName(bookName);
    if (book == nullptr) {
        return false;
    }

    user->addOwnedBook(*book);
    return true;
}

bool BookController::returnBookWithNameFromUserWithName(const std::string& bookName, const std::string& userName) {
    User* user = this->_store._users.getUserWithName(userName);
    if (user == nullptr) {
        return false;
    }

    const Book* book = this->_store._books.getBookWithName(bookName);
    if (book == nullptr) {
        return false;
    }

    user->removeOwnedBook(*book);
    return true;
}

Books::BookIterator BookController::booksBegin() const {
    return this->_store._books.booksBegin();
}

Books::BookIterator BookController::booksEnd() const {
    return this->_store._books.booksEnd();
}

