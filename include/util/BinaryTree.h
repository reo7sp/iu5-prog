#ifndef IU5_PROG_BINARYTREE_H
#define IU5_PROG_BINARYTREE_H

#include <vector>

template<typename... T>
class BinaryTree {
public:
    class Iterator : public std::iterator<std::input_iterator_tag, std::tuple<T...>> {
        friend BinaryTree;

    public:
        Iterator(const BinaryTree& tree, size_t i);
        Iterator(const Iterator& other);
        Iterator& operator++();
        const Iterator operator++(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        std::tuple<T...>& operator*() const;

    private:
        void _rewindToOkOrToEnd();

        const BinaryTree& _tree;
        size_t _i;
    };

    BinaryTree();

    ~BinaryTree();
    BinaryTree(const BinaryTree& other);
    BinaryTree& operator=(const BinaryTree& other);

    bool add(T... item);

    template<typename... K>
    bool remove(const K&... item);

    template<typename... K>
    bool has(const K&... item) const;

    template<typename... K>
    std::tuple<T...>* find(const K&... item) const;

    Iterator begin() const;
    Iterator end() const;
    size_t count() const;

private:
    struct _Node {
        std::tuple<T...>* data = nullptr;
    };

    template<typename... K>
    bool _findNode(size_t currentIndex, const std::tuple<K...>& key, size_t& out) const;

    _Node& _getNode(size_t index);
    const _Node& _getNode(size_t index) const;

    size_t _getParentIndex(size_t currentIndex) const;
    size_t _getLeftChildIndex(size_t currentIndex) const;
    size_t _getRightChildIndex(size_t currentIndex) const;
    size_t _getMinChildIndex(size_t currentIndex) const;
    size_t _getMaxChildIndex(size_t currentIndex) const;
    bool _getNextChildIndex(size_t currentIndex, size_t& out) const;
    bool _getPrevChildIndex(size_t currentIndex, size_t& out) const;

    mutable std::vector<_Node> _items;
    size_t _countItems = 0;
};

#endif //IU5_PROG_BINARYTREE_H

#include "BinaryTree.impl.h"
