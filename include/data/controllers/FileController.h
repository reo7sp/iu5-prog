#ifndef IU5_PROG_FILECONTROLLER_H
#define IU5_PROG_FILECONTROLLER_H

#include <string>

class DataStore;

class FileController {
public:
    explicit FileController(DataStore& store);

    bool loadByPath(const std::string& name);
    bool saveByPath(const std::string& name);

private:
    DataStore& _store;
};

#endif //IU5_PROG_FILECONTROLLER_H
