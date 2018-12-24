#ifndef IU5_PROG_BINARYTREE_IMPL_H
#define IU5_PROG_BINARYTREE_IMPL_H

#include "BinaryTree.h"

#include <utility>
#include "tuple-util.h"

template<typename... T>
BinaryTree<T...>::BinaryTree() {
}

template<typename... T>
BinaryTree<T...>::~BinaryTree() {
    for (_Node& n : this->_items) {
        if (n.data != nullptr) {
            delete n.data;
        }
    }
}

template<typename... T>
BinaryTree<T...>::BinaryTree(const BinaryTree<T...>& other) {
    this->_items.resize(other._items.size());
    for (size_t i = 0; i < other._items.size(); i++) {
        if (other._items[i].data != nullptr) {
            this->_items[i].data = new std::tuple<T...>(*other._items[i].data);
        }
    }
    this->_countItems = other._countItems;
}

template<typename... T>
BinaryTree<T...>& BinaryTree<T...>::operator=(const BinaryTree<T...>& other) {
    // clear
    for (_Node& n : this->_items) {
        if (n.data != nullptr) {
            delete n.data;
        }
    }
    this->_items.clear();

    // copy
    this->_items.resize(other._items.size());
    for (size_t i = 0; i < other._items.size(); ++i) {
        if (other._items[i].data != nullptr) {
            this->_items[i].data = new std::tuple<T...>(*other._items[i].data);
        }
    }

    this->_countItems = other._countItems;

    return *this;
}


template<typename... T>
bool BinaryTree<T...>::add(T... item) {
    // create
    auto* key = new std::tuple<T...>(item...);

    // find
    size_t insertPointIndex;
    const bool foundSame = this->_findNode(0, *key, insertPointIndex);
    if (foundSame) {
        delete key;
        return false;
    }

    // insert
    this->_getNode(insertPointIndex).data = key;
    ++this->_countItems;
    return true;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
template<typename... T>
template<typename... K>
bool BinaryTree<T...>::remove(const K&... item) {
    if (this->_items.empty()) {
        return false;
    }

    // find
    const auto key = std::tuple<K...>(item...);
    size_t foundNodeIndex;
    const bool ok = this->_findNode(0, key, foundNodeIndex);
    if (!ok) {
        return false;
    }

    // inverse getting order, because inner this->_items.resize() can reallocate the array and the reference become invalid
    _Node& rightChildNode = this->_getNode(this->_getRightChildIndex(foundNodeIndex));
    _Node& leftChildNode = this->_getNode(this->_getLeftChildIndex(foundNodeIndex));
    _Node& currentNode = this->_getNode(foundNodeIndex);

    const bool hasLeftChild = leftChildNode.data != nullptr;
    const bool hasRightChild = rightChildNode.data != nullptr;

    // delete
    delete currentNode.data;
    currentNode.data = nullptr;
    --this->_countItems;

    // handle children

    // // has no children case
    if (!hasLeftChild && !hasRightChild) {
        // do nothing
        return true;
    }
    
    // // has one child case
    if (hasLeftChild && !hasRightChild) {
        std::swap(leftChildNode.data, currentNode.data);
        return true;
    }
    if (!hasLeftChild && hasRightChild) {
        std::swap(rightChildNode.data, currentNode.data);
        return true;
    }

    // // has both children case
    if (hasLeftChild && hasRightChild) {
        size_t nextChildIndex;
        const bool nextChildOk = this->_getNextChildIndex(foundNodeIndex, nextChildIndex);
        if (!nextChildOk) {
            throw std::logic_error("impossible error");
        }
        _Node& nextChildNode = this->_getNode(nextChildIndex);
        std::swap(nextChildNode.data, currentNode.data);
        return true;
    }

    return true;
}
#pragma clang diagnostic pop

template<typename... T>
template<typename... K>
bool BinaryTree<T...>::has(const K&... item) const {
    if (this->_items.empty()) {
        return false;
    }

    const std::tuple<K...> key(item...);
    size_t foundNodeIndex;
    const bool ok = this->_findNode(0, key, foundNodeIndex);
    return ok;
}

template<typename... T>
template<typename... K>
std::tuple<T...>* BinaryTree<T...>::find(const K&... item) const {
    if (this->_items.empty()) {
        return nullptr;
    }

    const std::tuple<K...> key(item...);
    size_t foundNodeIndex;
    const bool ok = this->_findNode(0, key, foundNodeIndex);
    if (!ok) {
        return nullptr;
    }

    return this->_items[foundNodeIndex].data;
}

template<typename... T>
typename BinaryTree<T...>::Iterator BinaryTree<T...>::begin() const {
    Iterator iter(*this, 0);
    iter._rewindToOkOrToEnd();
    return iter;
}

template<typename... T>
typename BinaryTree<T...>::Iterator BinaryTree<T...>::end() const {
    return Iterator(*this, this->_items.size());
}

template<typename... T>
template<typename... K>
bool BinaryTree<T...>::_findNode(size_t currentIndex, const std::tuple<K...>& key, size_t& out) const {
    const _Node& currentNode = this->_getNode(currentIndex);
    if (currentNode.data == nullptr) {
        out = currentIndex;
        return false;
    }
    if (tupleUtil::isEqualPrefix(*currentNode.data, key)) {
        out = currentIndex;
        return true;
    }
    if (tupleUtil::isLess(key, *currentNode.data)) {
        return this->_findNode(_getLeftChildIndex(currentIndex), key, out);
    } else {
        return this->_findNode(_getRightChildIndex(currentIndex), key, out);
    }
}

template<typename... T>
typename BinaryTree<T...>::_Node& BinaryTree<T...>::_getNode(size_t index) {
    if (index >= this->_items.size()) {
        this->_items.resize(index + 1);
    }
    return this->_items[index];
}

template<typename... T>
const typename BinaryTree<T...>::_Node& BinaryTree<T...>::_getNode(size_t index) const {
    if (index >= this->_items.size()) {
        this->_items.resize(index + 1);
    }
    return this->_items[index];
}

template<typename... T>
size_t BinaryTree<T...>::_getParentIndex(size_t currentIndex) const {
    assert(currentIndex >= 1);
    return (currentIndex - 1) / 2;
}

template<typename... T>
size_t BinaryTree<T...>::_getLeftChildIndex(size_t currentIndex) const {
    return 2 * currentIndex + 1;
}

template<typename... T>
size_t BinaryTree<T...>::_getRightChildIndex(size_t currentIndex) const {
    return 2 * currentIndex + 2;
}

template<typename... T>
size_t BinaryTree<T...>::_getMinChildIndex(size_t currentIndex) const {
    const size_t leftChildIndex = this->_getLeftChildIndex(currentIndex);
    const _Node& leftChildNode = this->_getNode(leftChildIndex);
    const bool hasLeftChild = leftChildNode.data != nullptr;
    if (hasLeftChild) {
        return this->_getMinChildIndex(leftChildIndex);
    } else {
        return currentIndex;
    }
}

template<typename... T>
size_t BinaryTree<T...>::_getMaxChildIndex(size_t currentIndex) const {
    const size_t rightChildIndex = this->_getRightChildIndex(currentIndex);
    const _Node& rightChildNode = this->_getNode(rightChildIndex);
    const bool hasRightChild = rightChildNode.data != nullptr;
    if (hasRightChild) {
        return this->_getMaxChildIndex(rightChildIndex);
    } else {
        return currentIndex;
    }
}

template<typename... T>
bool BinaryTree<T...>::_getNextChildIndex(size_t currentIndex, size_t& out) const {
    const size_t rightChildIndex = this->_getRightChildIndex(currentIndex);
    const _Node& rightChildNode = this->_getNode(rightChildIndex);
    const bool hasRightChild = rightChildNode.data != nullptr;

    if (hasRightChild) {
        out = this->_getMinChildIndex(rightChildIndex);
        return true;
    } else {
        size_t movingCurrentIndex = currentIndex;
        size_t movingParentIndex;

        do {
            movingParentIndex = this->_getParentIndex(movingCurrentIndex);

            const bool isCurrentLeftChild = this->_getLeftChildIndex(movingParentIndex) == movingCurrentIndex;
            if (isCurrentLeftChild) {
                out = movingCurrentIndex;
                return true;
            }

            movingCurrentIndex = movingParentIndex;
        } while (movingCurrentIndex != 0);

        return false;
    }
}

template<typename... T>
bool BinaryTree<T...>::_getPrevChildIndex(size_t currentIndex, size_t& out) const {
    const size_t leftChildIndex = this->_getLeftChildIndex(currentIndex);
    const _Node& leftChildNode = this->_getNode(leftChildIndex);
    const bool hasLeftChild = leftChildNode.data != nullptr;

    if (hasLeftChild) {
        out = this->_getMaxChildIndex(leftChildIndex);
        return true;
    } else {
        size_t movingCurrentIndex = currentIndex;
        size_t movingParentIndex;

        do {
            movingParentIndex = this->_getParentIndex(movingCurrentIndex);

            const bool isCurrentRightChild = this->_getRightChildIndex(movingParentIndex) == movingCurrentIndex;
            if (isCurrentRightChild) {
                out = movingCurrentIndex;
                return true;
            }

            movingCurrentIndex = movingParentIndex;
        } while (movingCurrentIndex != 0);

        return false;
    }
}

template<typename... T>
size_t BinaryTree<T...>::count() const {
    return this->_countItems;
}

template<typename... T>
BinaryTree<T...>::Iterator::Iterator(const BinaryTree<T...>& tree, size_t i) : _tree(tree), _i(i) {
}

template<typename... T>
BinaryTree<T...>::Iterator::Iterator(const BinaryTree<T...>::Iterator& other) : _tree(other._tree), _i(other._i) {
}

template<typename... T>
typename BinaryTree<T...>::Iterator& BinaryTree<T...>::Iterator::operator++() {
    if (this->_i >= this->_tree._items.size()) {
        throw std::out_of_range("iterator is done");
    }
    this->_i++;
    this->_rewindToOkOrToEnd();
    return *this;
}

template<typename... T>
const typename BinaryTree<T...>::Iterator BinaryTree<T...>::Iterator::operator++(int) {
    Iterator copy(*this);
    ++(*this);
    return copy;
}

template<typename... T>
bool BinaryTree<T...>::Iterator::operator==(const BinaryTree<T...>::Iterator& other) const {
    return this->_i == other._i;
}

template<typename... T>
bool BinaryTree<T...>::Iterator::operator!=(const BinaryTree<T...>::Iterator& other) const {
    return !(*this == other);
}

template<typename... T>
std::tuple<T...>& BinaryTree<T...>::Iterator::operator*() const {
    if (this->_i >= this->_tree._items.size()) {
        throw std::out_of_range("iterator is done");
    }
    return *this->_tree._items[this->_i].data;
}

template<typename... T>
void BinaryTree<T...>::Iterator::_rewindToOkOrToEnd() {
    while (true) {
        const bool isEnd = this->_i >= this->_tree._items.size();
        if (isEnd) {
            break;
        }
        const bool isOk = this->_tree._items[this->_i].data != nullptr;
        if (isOk) {
            break;
        }
        this->_i++;
    }
}

#endif //IU5_PROG_BINARYTREE_IMPL_H
