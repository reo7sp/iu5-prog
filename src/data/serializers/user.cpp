#include "data/serializers/user.h"
#include "data/serializers/string.h"
#include "data/serializers/book.h"

void serializeUser(std::ostream& out, const User& user) {
    serializeString(out, user.getName());

    out << user.ownedBooksCount() << std::endl;
    for (auto iterBook = user.ownedBooksBegin(), endBook = user.ownedBooksEnd(); iterBook != endBook; ++iterBook) {
        const Book& book = *iterBook;
        serializeBook(out, book);
    }
}

User unserializeUser(std::istream& in) {
    std::string userName = unserializeString(in);

    User user(userName);

    size_t ownedBooksCount;
    in >> ownedBooksCount;
    for (size_t j = 0; j < ownedBooksCount; ++j) {
        Book book = unserializeBook(in);
        user.addOwnedBook(book);
    }

    return user;
}