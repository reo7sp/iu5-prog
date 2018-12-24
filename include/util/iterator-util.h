#ifndef IU5_PROG_ITERATOR_UTIL_H
#define IU5_PROG_ITERATOR_UTIL_H

#include <iterator>

template<typename Item, typename Iter, size_t TupleFieldNo>
class TupleFieldGetterIteratorWrapper : public std::iterator<std::input_iterator_tag, Item> {
public:
    explicit TupleFieldGetterIteratorWrapper(Iter iter);
    TupleFieldGetterIteratorWrapper(const TupleFieldGetterIteratorWrapper& other);
    TupleFieldGetterIteratorWrapper& operator++();
    const TupleFieldGetterIteratorWrapper operator++(int);
    bool operator==(const TupleFieldGetterIteratorWrapper& other) const;
    bool operator!=(const TupleFieldGetterIteratorWrapper& other) const;
    Item& operator*() const;

private:
    Iter _iter;
};

#endif //IU5_PROG_ITERATOR_UTIL_H

#include "iterator-util.impl.h"
