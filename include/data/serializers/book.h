#ifndef IU5_PROG_SERIALIZERS_BOOK_H
#define IU5_PROG_SERIALIZERS_BOOK_H

#include <fstream>
#include "data/models/Book.h"

void serializeBook(std::ostream& out, const Book& book);
Book unserializeBook(std::istream& in);

#endif //IU5_PROG_SERIALIZERS_BOOK_H
