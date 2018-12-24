#include "ui/menu.h"

#include <iostream>

#include "data/models/User.h"

enum _State {
    MAIN_MENU,
    PEOPLE_MENU,
    BOOK_MENU,
    FILE_MENU,
    EXIT
};

_State _handleMainMenu(DataStore& store) {
    std::cout << "@ Главное меню:" << std::endl;
    std::cout << "1 - показать меню людей" << std::endl;
    std::cout << "2 - показать меню книг" << std::endl;
    std::cout << "3 - показать меню файл" << std::endl;
    std::cout << "0 - выйти" << std::endl;
    std::cout << "Выберите вариант: ";

    std::string choice;
    std::cin >> choice;

    if (choice == "1") {
        return _State::PEOPLE_MENU;
    } else if (choice == "2") {
        return _State::BOOK_MENU;
    } else if (choice == "3") {
        return _State::FILE_MENU;
    } else if (choice == "0") {
        return _State::EXIT;
    } else {
        return _State::MAIN_MENU;
    }
}

_State _handlePeopleMenu(DataStore& store) {
    std::cout << "@ Меню людей:" << std::endl;
    std::cout << "1 - добавить человека" << std::endl;
    std::cout << "2 - удалить человека" << std::endl;
    std::cout << "3 - вывести список" << std::endl;
    std::cout << "0 - вернуться в главное меню" << std::endl;
    std::cout << "Выберите вариант: ";

    std::string choice;
    std::cin >> choice;

    std::string name;
    if (choice == "1") {
        std::cout << "Напишите имя: ";
        std::cin >> name;
        const bool ok = store.getUserController().addUserWithName(name);
        if (!ok) {
            std::cout << "Уже есть такой человек";
            return _State::PEOPLE_MENU;
        }
        std::cout << "ОК";
        return _State::PEOPLE_MENU;
    } else if (choice == "2") {
        std::cout << "Напишите имя: ";
        std::cin >> name;
        const bool ok = store.getUserController().removeUserWithName(name);
        if (!ok) {
            std::cout << "Нет такого человека";
            return _State::PEOPLE_MENU;
        }
        std::cout << "ОК";
        return _State::PEOPLE_MENU;
    } else if (choice == "3") {
        std::cout << "Имя" << std::endl;
        std::cout << "-----" << std::endl;
        for (auto iter = store.getUserController().usersBegin(), endIter = store.getUserController().usersEnd(); iter != endIter; ++iter) {
            const User& user = *iter;
            std::cout << user.getName() << std::endl;
        }
        return _State::PEOPLE_MENU;
    } else if (choice == "0") {
        return _State::MAIN_MENU;
    } else {
        return _State::PEOPLE_MENU;
    }
}

_State _handleBookMenu(DataStore& store) {
    std::cout << "@ Меню книг:" << std::endl;
    std::cout << "1 - добавить книгу" << std::endl;
    std::cout << "2 - удалить книгу" << std::endl;
    std::cout << "3 - вывести список" << std::endl;
    std::cout << "4 - дать книгу человеку" << std::endl;
    std::cout << "5 - отобрать книгу у человека" << std::endl;
    std::cout << "6 - посмотреть список книг у человека" << std::endl;
    std::cout << "0 - вернуться в главное меню" << std::endl;
    std::cout << "Выберите вариант: ";

    std::string choice;
    std::cin >> choice;

    std::string name, name2;
    if (choice == "1") {
        std::cout << "Напишите имя: ";
        std::cin >> name;
        std::cout << "Напишите имя предмета: ";
        std::cin >> name2;
        const bool ok = store.getBookController().addBookWithNameAndSubjectName(name, name2);
        if (!ok) {
            std::cout << "Уже есть такая книга";
            return _State::BOOK_MENU;
        }
        std::cout << "ОК";
        return _State::BOOK_MENU;
    } else if (choice == "2") {
        std::cout << "Напишите имя: ";
        std::cin >> name;
        const bool ok = store.getBookController().removeBookWithName(name);
        if (!ok) {
            std::cout << "Нет такой книги";
            return _State::BOOK_MENU;
        }
        std::cout << "ОК";
        return _State::BOOK_MENU;
    } else if (choice == "3") {
        std::cout << "Имя, Имя предмета" << std::endl;
        std::cout << "-----" << std::endl;
        for (auto iter = store.getBookController().booksBegin(), end = store.getBookController().booksEnd(); iter != end; ++iter) {
            const Book& book = *iter;
            std::cout << book.getName() << ", " << book.getSubject().getName() << std::endl;
        }
        return _State::BOOK_MENU;
    } else if (choice == "4") {
        std::cout << "Напишите имя книги: ";
        std::cin >> name;
        std::cout << "Напишите имя человека: ";
        std::cin >> name2;
        const bool ok = store.getBookController().giveBookWithNameToUserWithName(name, name2);
        if (!ok) {
            std::cout << "Неудача";
            return _State::BOOK_MENU;
        }
        std::cout << "ОК";
        return _State::BOOK_MENU;
    } else if (choice == "5") {
        std::cout << "Напишите имя книги: ";
        std::cin >> name;
        std::cout << "Напишите имя человека: ";
        std::cin >> name2;
        const bool ok = store.getBookController().returnBookWithNameFromUserWithName(name, name2);
        if (!ok) {
            std::cout << "Неудача";
            return _State::BOOK_MENU;
        }
        std::cout << "ОК";
        return _State::BOOK_MENU;
    } else if (choice == "6") {
        std::cout << "Напишите имя человека: ";
        std::cin >> name;
        const User* user = store.getUserController().getUserWithName(name);
        if (user == nullptr) {
            std::cout << "Нет такого человека";
            return _State::BOOK_MENU;
        }
        std::cout << "Имя, Имя предмета" << std::endl;
        std::cout << "-----" << std::endl;
        for (auto iter = user->ownedBooksBegin(), end = user->ownedBooksEnd(); iter != end; ++iter) {
            const Book& book = *iter;
            std::cout << book.getName() << ", " << book.getSubject().getName() << std::endl;
        }
        return _State::BOOK_MENU;
    } else if (choice == "0") {
        return _State::MAIN_MENU;
    } else {
        return _State::BOOK_MENU;
    }
}

_State _handleFileMenu(DataStore& store) {
    std::cout << "@ Меню файл:" << std::endl;
    std::cout << "1 - загрузить" << std::endl;
    std::cout << "2 - сохранить" << std::endl;
    std::cout << "0 - вернуться в главное меню" << std::endl;
    std::cout << "Выберите вариант: ";

    std::string choice;
    std::cin >> choice;

    std::string name;
    if (choice == "1") {
        std::cout << "Напишите имя файла: ";
        std::cin >> name;
        const bool ok = store.getFileController().loadByPath(name);
        if (!ok) {
            std::cout << "Нет такого файла";
            return _State::FILE_MENU;
        }
        std::cout << "ОК";
        return _State::FILE_MENU;
    } else if (choice == "2") {
        std::cout << "Напишите имя файла: ";
        std::cin >> name;
        const bool ok = store.getFileController().saveByPath(name);
        if (!ok) {
            std::cout << "Не получается записать в файл";
            return _State::FILE_MENU;
        }
        std::cout << "ОК";
        return _State::FILE_MENU;
    } else if (choice == "0") {
        return _State::MAIN_MENU;
    } else {
        return _State::FILE_MENU;
    }
}

void startMenuLoop(DataStore& store) {
    _State state = _State::MAIN_MENU;
    while (state != _State::EXIT) {
        switch (state) {
            case _State::MAIN_MENU: {
                state = _handleMainMenu(store);
                break;
            }
            case _State::PEOPLE_MENU: {
                state = _handlePeopleMenu(store);
                break;
            }
            case _State::BOOK_MENU: {
                state = _handleBookMenu(store);
                break;
            }
            case _State::FILE_MENU: {
                state = _handleFileMenu(store);
                break;
            }
            case EXIT: {
                break;
            }
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
