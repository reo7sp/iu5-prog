#include "data/models/Users.h"

#include "util/iterator-util.h"

bool Users::addUser(User user) {
    return this->_users.add(user.getName(), user);
}

bool Users::removeUser(const User& user) {
    return this->_users.remove(user.getName(), user);
}

bool Users::removeUserWithName(const std::string& name) {
    return this->_users.remove(name);
}

bool Users::hasUser(const User& book) const {
    return this->_users.has(book.getName(), book);
}

bool Users::hasUserWithName(const std::string& name) const {
    return this->_users.has(name);
}

User* Users::getUserWithName(const std::string& name) {
    std::tuple<std::string, User>* t = this->_users.find(name);
    if (t == nullptr) {
        return nullptr;
    }

    User& user = std::get<1>(*t);
    return &user;
}

const User* Users::getUserWithName(const std::string& name) const {
    const std::tuple<std::string, User>* t = this->_users.find(name);
    if (t == nullptr) {
        return nullptr;
    }

    const User& user = std::get<1>(*t);
    return &user;
}

Users::UserIterator Users::usersBegin() const {
    return UserIterator(this->_users.begin());
}

Users::UserIterator Users::usersEnd() const {
    return UserIterator(this->_users.end());
}


size_t Users::count() const {
    return this->_users.count();
}
