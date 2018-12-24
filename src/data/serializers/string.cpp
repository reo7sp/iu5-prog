#include "data/serializers/string.h"

void serializeString(std::ostream& out, const std::string& s) {
    out << s.size() << std::endl;
    out.write(s.data(), s.size());
    out << std::endl;
}

std::string unserializeString(std::istream& in) {
    size_t strSize;
    in >> strSize;
    char* strBuffer = new char[strSize+1];
    in.seekg((int) in.tellg() + 1);
    in.read(strBuffer, strSize);
    strBuffer[strSize] = '\0';

    std::string result(strBuffer);

    delete[] strBuffer;

    return result;
}