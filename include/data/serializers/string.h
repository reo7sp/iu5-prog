#ifndef IU5_PROG_STRING_H
#define IU5_PROG_STRING_H

#include <fstream>
#include <string>

void serializeString(std::ostream& out, const std::string& book);
std::string unserializeString(std::istream& in);

#endif //IU5_PROG_STRING_H
