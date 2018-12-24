
#include <data/models/Subject.h>

#include "data/models/Subject.h"

Subject::Subject() = default;

Subject::Subject(std::string name) : _name(std::move(name)) {
}

std::string Subject::getName() const {
    return this->_name;
}

bool Subject::operator<(const Subject& other) const {
    if (this->_name != other._name) {
        return this->_name < other._name;
    }
    return false;
}

bool Subject::operator==(const Subject& other) const {
    return this->_name == other._name;
}

bool Subject::operator!=(const Subject& other) const {
    return !(*this == other);
}


