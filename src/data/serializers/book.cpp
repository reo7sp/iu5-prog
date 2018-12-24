#include "data/serializers/book.h"

#include "data/models/Subject.h"
#include "data/serializers/string.h"

void serializeBook(std::ostream& out, const Book& book) {
    serializeString(out, book.getName());
    serializeString(out, book.getSubject().getName());
}

Book unserializeBook(std::istream& in) {
    std::string bookName = unserializeString(in);
    std::string subjectName = unserializeString(in);
    return Book(bookName, Subject(subjectName));
}