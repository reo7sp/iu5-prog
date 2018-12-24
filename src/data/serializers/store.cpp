#include "data/serializers/store.h"

#include "data/models/Subject.h"
#include "data/serializers/book.h"
#include "data/serializers/user.h"

void serializeStore(std::ostream& out, const Books& books, const Users& users) {
    out << books.count() << std::endl;
    for (auto iter = books.booksBegin(), end = books.booksEnd(); iter != end; ++iter) {
        serializeBook(out, *iter);
    }

    out << users.count() << std::endl;
    for (auto iter = users.usersBegin(), end = users.usersEnd(); iter != end; ++iter) {
        serializeUser(out, *iter);
    }
}

std::tuple<Books, Users> unserializeStore(std::istream& in) {
    std::tuple<Books, Users> result;

    size_t booksCount;
    in >> booksCount;
    for (size_t i = 0; i < booksCount; ++i) {
        std::get<0>(result).addBook(unserializeBook(in));
    }

    size_t usersCount;
    in >> usersCount;
    for (size_t i = 0; i < usersCount; ++i) {
        std::get<1>(result).addUser(unserializeUser(in));
    }

    return result;
}