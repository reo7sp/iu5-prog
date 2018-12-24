#ifndef IU5_PROG_STORE_H
#define IU5_PROG_STORE_H

#include "data/controllers/UserController.h"
#include "data/controllers/BookController.h"
#include "data/controllers/FileController.h"
#include "data/models/Books.h"
#include "data/models/Users.h"

class DataStore {
    friend UserController;
    friend BookController;
    friend FileController;

public:
    DataStore();

    UserController& getUserController();
    BookController& getBookController();
    FileController& getFileController();

private:
    UserController _userController;
    BookController _bookController;
    FileController _fileController;
    Books _books;
    Users _users;
};

#endif //IU5_PROG_STORE_H
