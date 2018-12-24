#include "data/DataStore.h"

DataStore::DataStore() : _userController(*this), _bookController(*this), _fileController(*this) {

}

UserController& DataStore::getUserController() {
    return this->_userController;
}

BookController& DataStore::getBookController() {
    return this->_bookController;
}

FileController& DataStore::getFileController() {
    return this->_fileController;
}
