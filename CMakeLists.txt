cmake_minimum_required(VERSION 3.13)
project(iu5_prog)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(
        iu5_prog
        src/data/controllers/BookController.cpp
        src/data/controllers/FileController.cpp
        src/data/controllers/UserController.cpp
        src/data/models/Books.cpp
        src/data/models/Book.cpp
        src/data/models/Subject.cpp
        src/data/models/User.cpp
        src/data/models/Users.cpp
        src/data/serializers/store.cpp
        src/data/serializers/book.cpp
        src/data/serializers/string.cpp
        src/data/serializers/user.cpp
        src/data/DataStore.cpp
        src/ui/menu.cpp
        src/main.cpp
        src/data/serializers/string.cpp)