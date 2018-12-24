#ifndef IU5_PROG_USERS_H
#define IU5_PROG_USERS_H

#include <string>
#include "util/BinaryTree.h"
#include "Subject.h"
#include "Book.h"
#include "User.h"

class Users {
public:
    typedef TupleFieldGetterIteratorWrapper<User, BinaryTree<std::string, User>::Iterator, 1> UserIterator;

    bool addUser(User user);
    bool removeUser(const User& user);
    bool removeUserWithName(const std::string& name);
    bool hasUser(const User& user) const;
    bool hasUserWithName(const std::string& name) const;
    User* getUserWithName(const std::string& name);
    const User* getUserWithName(const std::string& name) const;
    UserIterator usersBegin() const;
    UserIterator usersEnd() const;
    size_t count() const;

private:
    BinaryTree<std::string, User> _users;
};

#endif //IU5_PROG_USERS_H
