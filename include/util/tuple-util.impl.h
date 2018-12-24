#ifndef IU5_PROG_TUPLE_UTIL_IMPL_H
#define IU5_PROG_TUPLE_UTIL_IMPL_H

#include <tuple>

namespace tupleUtil {

    namespace _isLessImpl {
        template<size_t MaxSizeL, size_t MaxSizeR, size_t CurTailSizeL, size_t CurTailSizeR>
        struct lessOp {
            template<typename... L, typename... R>
            static bool call(const std::tuple<L...>& left, const std::tuple<R...>& right) {
                return std::get<MaxSizeL-CurTailSizeL>(left) < std::get<MaxSizeR-CurTailSizeR>(right) &&
                       lessOp<MaxSizeL, MaxSizeR, CurTailSizeL-1, CurTailSizeR-1>::call(left, right);
            }
        };

        // if both are equal
        template<size_t MaxSizeL, size_t MaxSizeR>
        struct lessOp<MaxSizeL, MaxSizeR, 0, 0> {
            template<typename... L, typename... R>
            static bool call(const std::tuple<L...>& left, const std::tuple<R...>& right) {
                return false;
            }
        };

        // if first has less elements
        template<size_t MaxSizeL, size_t MaxSizeR, size_t CurTailSizeR>
        struct lessOp<MaxSizeL, MaxSizeR, 0, CurTailSizeR> {
            template<typename... L, typename... R>
            static bool call(const std::tuple<L...>& left, const std::tuple<R...>& right) {
                return true;
            }
        };

        // if first has more elements
        template<size_t MaxSizeL, size_t MaxSizeR, size_t CurTailSizeL>
        struct lessOp<MaxSizeL, MaxSizeR, CurTailSizeL, 0> {
            template<typename... L, typename... R>
            static bool call(const std::tuple<L...>& left, const std::tuple<R...>& right) {
                return false;
            }
        };
    }

    template<typename... L, typename... R>
    bool isLess(const std::tuple<L...>& left, const std::tuple<R...>& right) {
        return _isLessImpl::lessOp<sizeof...(L), sizeof...(R), sizeof...(L), sizeof...(R)>::call(left, right);
    }

    namespace _isEqualPrefixImpl {
        template<size_t MaxSizeL, size_t MaxSizeR, size_t CurTailSizeL, size_t CurTailSizeR>
        struct equalOp {
            template<typename... L, typename... R>
            static bool call(const std::tuple<L...>& big, const std::tuple<R...>& prefix) {
                return std::get<MaxSizeL-CurTailSizeL>(big) == std::get<MaxSizeR-CurTailSizeR>(prefix) &&
                       equalOp<MaxSizeL, MaxSizeR, CurTailSizeL-1, CurTailSizeR-1>::call(big, prefix);
            }
        };

        // if both are equal
        template<size_t MaxSizeL, size_t MaxSizeR>
        struct equalOp<MaxSizeL, MaxSizeR, 0, 0> {
            template<typename... L, typename... R>
            static bool call(const std::tuple<L...>& big, const std::tuple<R...>& prefix) {
                return true;
            }
        };

        // if first has less elements
        template<size_t MaxSizeL, size_t MaxSizeR, size_t CurTailSizeR>
        struct equalOp<MaxSizeL, MaxSizeR, 0, CurTailSizeR> {
            template<typename... L, typename... R>
            static bool call(const std::tuple<L...>& big, const std::tuple<R...>& prefix) {
                return false;
            }
        };

        // if first has more elements
        template<size_t MaxSizeL, size_t MaxSizeR, size_t CurTailSizeL>
        struct equalOp<MaxSizeL, MaxSizeR, CurTailSizeL, 0> {
            template<typename... L, typename... R>
            static bool call(const std::tuple<L...>& big, const std::tuple<R...>& prefix) {
                return true;
            }
        };
    }

    template<typename... L, typename... R>
    bool isEqualPrefix(const std::tuple<L...>& big, const std::tuple<R...>& prefix) {
        return _isEqualPrefixImpl::equalOp<sizeof...(L), sizeof...(R), sizeof...(L), sizeof...(R)>::call(big, prefix);
    }

}

#endif //IU5_PROG_TUPLE_UTIL_IMPL_H
