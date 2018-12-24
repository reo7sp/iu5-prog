#ifndef IU5_PROG_BOOKS_H
#define IU5_PROG_BOOKS_H

#include "Book.h"
#include "util/BinaryTree.h"
#include "util/iterator-util.h"

class Books {
public:
    typedef TupleFieldGetterIteratorWrapper<Book, BinaryTree<std::string, Book>::Iterator, 1> BookIterator;

    bool addBook(Book book);
    bool removeBook(const Book& book);
    bool removeBookWithName(const std::string& name);
    bool hasBook(const Book& book) const;
    bool hasBookWithName(const std::string& name) const;
    Book* getBookWithName(const std::string& name);
    const Book* getBookWithName(const std::string& name) const;
    BookIterator booksBegin() const;
    BookIterator booksEnd() const;
    size_t count() const;

private:
    BinaryTree<std::string, Book> _books;
};

#endif //IU5_PROG_BOOKS_H
