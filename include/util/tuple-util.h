#ifndef IU5_PROG_TUPLE_UTIL_H
#define IU5_PROG_TUPLE_UTIL_H

#include <tuple>

namespace tupleUtil {

    template<typename... L, typename... R>
    bool isLess(const std::tuple<L...>& left, const std::tuple<R...>& right);

    template<typename... L, typename... R>
    bool isEqualPrefix(const std::tuple<L...>& big, const std::tuple<R...>& prefix);

}

#endif //IU5_PROG_TUPLE_UTIL_H

#include "tuple-util.impl.h"
