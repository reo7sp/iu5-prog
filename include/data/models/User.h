#ifndef IU5_PROG_USER_H
#define IU5_PROG_USER_H

#include <string>
#include "util/BinaryTree.h"
#include "Subject.h"
#include "Book.h"
#include "util/iterator-util.h"

class User {
public:
    typedef TupleFieldGetterIteratorWrapper<Book, BinaryTree<Subject, Book>::Iterator, 1> BookIterator;

    User();
    explicit User(std::string name);

    std::string getName() const;
    bool addOwnedBook(Book book);
    bool removeOwnedBook(const Book& book);
    bool hasOwnedBook(const Book& book) const;
    bool hasOwnedBookWithSubject(const Subject& subject) const;
    BookIterator ownedBooksBegin() const;
    BookIterator ownedBooksEnd() const;
    size_t ownedBooksCount() const;

    bool operator<(const User& other) const;
    bool operator==(const User& other) const;
    bool operator!=(const User& other) const;

private:
    std::string _name;
    BinaryTree<Subject, Book> _ownedBooks;
};

#endif //IU5_PROG_USER_H
