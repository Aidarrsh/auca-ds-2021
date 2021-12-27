#pragma once
#include <utility>

template <typename ForwardIter, typename Key>
ForwardIter auFind(ForwardIter beg, ForwardIter end, Key &key){
    while (beg != end){
        if (*beg == key){
            return beg;
        }
        beg++;
    }
    return beg;
}

template <typename T>
void auSwap(T &x, T &y){
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}

template <typename BidirectionalIter>
void auReverse(BidirectionalIter *begin, BidirectionalIter *end){
    for (;;){
        if (begin == end){
            break;
        }
        --end;
        if (begin == end){
            break;
        }
        BidirectionalIter temp;
        temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
    }
}

template <typename ForwardIter , typename Key>
ForwardIter auFind(ForwardIter beg, ForwardIter end, Key key){
    while (beg != end){
        if (*beg == key){
            return beg;
        }
        beg++;
    }
    return beg;
}

template <typename ForwardIter, typename UnaryPredicate>
ForwardIter auFind_if(ForwardIter beg, ForwardIter end, UnaryPredicate pred){
    while (beg!= end){
        if (pred(*beg)){
            return beg;
        }
        beg++;
    }
    return beg;
}

template <typename ForwardIter>
ForwardIter auMinElement(ForwardIter beg, ForwardIter end){
    ForwardIter it = beg;

    while (beg != end){
        if (*beg < *it){
            it = beg;
        }
        beg++;
    }
    return it;
}

template <typename ForwardIter, typename UnaryPredicate>
ForwardIter auMinElement_by(ForwardIter beg, ForwardIter end, UnaryPredicate pred){
ForwardIter it = beg;

    while (beg != end){
        if (pred(*beg, *it)){
            it = beg;
        }
        beg++;
    }
    return it;
}

template <typename AnyIter, typename Obj>
bool auBinarySearch(AnyIter beg, AnyIter end, Obj x){
    AnyIter l = beg, r = end, m = beg + (end - beg) /2;

    while (*m != x && m != r){
        if (*m > x){
            l = m + 1;
        } else {
            r = m;
        }

        m = l + (r - l) / 2;
    }
    if (*m == x){
        return true;
    }
    return false;
}