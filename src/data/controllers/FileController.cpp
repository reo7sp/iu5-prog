#include "data/controllers/FileController.h"

#include <fstream>

#include "data/DataStore.h"
#include "data/serializers/book.h"
#include "data/serializers/user.h"
#include "data/serializers/store.h"


FileController::FileController(DataStore& store) : _store(store) {
}

bool FileController::loadByPath(const std::string& name) {
    std::ifstream file(name);
    if (file.fail()) {
        return false;
    }

    std::tuple<Books, Users> loaded = unserializeStore(file);
    this->_store._books = std::move(std::get<0>(loaded));
    this->_store._users = std::move(std::get<1>(loaded));

    file.close();
    return true;
}

bool FileController::saveByPath(const std::string& name) {
    std::ofstream file(name);
    if (file.fail()) {
        return false;
    }

    serializeStore(file, this->_store._books, this->_store._users);

    file.close();
    return true;
}
