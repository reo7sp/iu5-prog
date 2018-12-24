#ifndef IU5_PROG_ITERATOR_UTIL_IMPL_H
#define IU5_PROG_ITERATOR_UTIL_IMPL_H

#include "iterator-util.h"

template<typename Item, typename Iter, size_t TupleFieldNo>
TupleFieldGetterIteratorWrapper<Item, Iter, TupleFieldNo>::TupleFieldGetterIteratorWrapper(Iter iter) : _iter(iter) {
}

template<typename Item, typename Iter, size_t TupleFieldNo>
TupleFieldGetterIteratorWrapper<Item, Iter, TupleFieldNo>::TupleFieldGetterIteratorWrapper(
        const TupleFieldGetterIteratorWrapper& other) : _iter(other._iter) {
}

template<typename Item, typename Iter, size_t TupleFieldNo>
TupleFieldGetterIteratorWrapper<Item, Iter, TupleFieldNo>& TupleFieldGetterIteratorWrapper<Item, Iter, TupleFieldNo>::operator++() {
    ++this->_iter;
    return *this;
}

template<typename Item, typename Iter, size_t TupleFieldNo>
const TupleFieldGetterIteratorWrapper<Item, Iter, TupleFieldNo> TupleFieldGetterIteratorWrapper<Item, Iter, TupleFieldNo>::operator++(int) {
    TupleFieldGetterIteratorWrapper copy(*this);
    ++(*this);
    return copy;
}

template<typename Item, typename Iter, size_t TupleFieldNo>
bool TupleFieldGetterIteratorWrapper<Item, Iter, TupleFieldNo>::operator==(const TupleFieldGetterIteratorWrapper& other) const {
    return this->_iter == other._iter;
}

template<typename Item, typename Iter, size_t TupleFieldNo>
bool TupleFieldGetterIteratorWrapper<Item, Iter, TupleFieldNo>::operator!=(const TupleFieldGetterIteratorWrapper& other) const {
    return this->_iter != other._iter;
}

template<typename Item, typename Iter, size_t TupleFieldNo>
Item& TupleFieldGetterIteratorWrapper<Item, Iter, TupleFieldNo>::operator*() const {
    return std::get<TupleFieldNo>(*this->_iter);
}

#endif //IU5_PROG_ITERATOR_UTIL_IMPL_H
