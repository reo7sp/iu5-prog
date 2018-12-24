#include "data/models/Books.h"

#include <utility>

#include "data/models/Book.h"

bool Books::addBook(Book book) {
    return this->_books.add(book.getName(), book);
}

bool Books::removeBook(const Book& book) {
    return this->_books.remove(book.getName(), book);
}

bool Books::removeBookWithName(const std::string& name) {
    return this->_books.remove(name);
}

bool Books::hasBook(const Book& book) const {
    return this->_books.has(book.getName(), book);
}

bool Books::hasBookWithName(const std::string& name) const {
    return this->_books.has(name);
}

Book* Books::getBookWithName(const std::string& name) {
    std::tuple<std::string, Book>* t = this->_books.find(name);
    if (t == nullptr) {
        return nullptr;
    }

    Book& book = std::get<1>(*t);
    return &book;
}

const Book* Books::getBookWithName(const std::string& name) const {
    const std::tuple<std::string, Book>* t = this->_books.find(name);
    if (t == nullptr) {
        return nullptr;
    }

    const Book& book = std::get<1>(*t);
    return &book;
}

Books::BookIterator Books::booksBegin() const {
    return BookIterator(this->_books.begin());
}

Books::BookIterator Books::booksEnd() const {
    return BookIterator(this->_books.end());
}

size_t Books::count() const {
    return this->_books.count();
}
