#include "PmergeMe.hpp"

template <typename CONT>
void FordJohanson(CONT &cont, typename CONT::iterator start, typename CONT::iterator end) {
    typename CONT::iterator previousCnt = start;
    typename CONT::iterator previousCnt1 = start + 1;
    typename CONT::value_type theValue = *previousCnt;

    for (; previousCnt != end && previousCnt1 != end; previousCnt += 2) {
        if (*previousCnt > *previousCnt1) {
            std::swap(*previousCnt, *previousCnt1);
        }
        previousCnt1 += 2;
    }
}