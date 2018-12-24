
#include <data/controllers/UserController.h>

#include "data/controllers/UserController.h"

#include "data/DataStore.h"

UserController::UserController(DataStore& store) : _store(store) {
}

bool UserController::addUserWithName(std::string name) {
    return this->_store._users.addUser(User(std::move(name)));
}

bool UserController::removeUserWithName(const std::string& name) {
    return this->_store._users.removeUserWithName(name);
}

const User* UserController::getUserWithName(const std::string& name) const {
    return this->_store._users.getUserWithName(name);
}

Users::UserIterator UserController::usersBegin() const {
    return this->_store._users.usersBegin();
}

Users::UserIterator UserController::usersEnd() const {
    return this->_store._users.usersEnd();
}
