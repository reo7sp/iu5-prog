#ifndef IU5_PROG_USERCONTROLLER_H
#define IU5_PROG_USERCONTROLLER_H

#include <string>
#include "data/models/Users.h"
#include "data/models/User.h"

class DataStore;

class UserController {
public:
    explicit UserController(DataStore& store);

    bool addUserWithName(std::string name);
    bool removeUserWithName(const std::string& name);
    const User* getUserWithName(const std::string& name) const;
    Users::UserIterator usersBegin() const;
    Users::UserIterator usersEnd() const;

private:
    DataStore& _store;
};

#endif //IU5_PROG_USERCONTROLLER_H
