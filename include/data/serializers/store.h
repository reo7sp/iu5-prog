#ifndef IU5_PROG_SERIALIZERS_STORE_H
#define IU5_PROG_SERIALIZERS_STORE_H

#include <fstream>
#include "data/models/Books.h"
#include "data/models/Users.h"

void serializeStore(std::ostream& out, const Books& books, const Users& users);
std::tuple<Books, Users> unserializeStore(std::istream& in);

#endif //IU5_PROG_SERIALIZERS_STORE_H
