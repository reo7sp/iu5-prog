#ifndef IU5_PROG_SERIALIZERS_USER_H
#define IU5_PROG_SERIALIZERS_USER_H

#include <fstream>
#include "data/models/User.h"

void serializeUser(std::ostream& out, const User& user);
User unserializeUser(std::istream& in);

#endif //IU5_PROG_SERIALIZERS_USER_H
