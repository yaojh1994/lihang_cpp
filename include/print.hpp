
#ifndef PRINT_HPP
#define PRINT_HPP

#include <iostream>
#include <string>

// PRINT_ELEMENTS()
// - prints optional string optstr followed by
// - all elements of the collection coll
// - in one line, separated by spaces
template <typename T>
inline void PRINT_ELEMENTS (const T& coll, const std::string& optstr="") {
    std::cout << optstr;
    for (const auto&  elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

//INSERT_ELEMENTS(collection,first,last)
// - fill valuesfromfirst   to last  into  the  collection
// - NOTE:NO half-openrange
template<typename T>
inline void INSERT_ELEMENTS (T& coll, int first, int last) {
    for (int i=first; i<=last; ++i) {
        coll.insert(coll.end(), i);
    }
}

template<typename T>
inline void PRINT_MAPPED_ELEMENTS (T& coll, const std::string& optstr="") {
    std::cout << optstr;
    for (auto elem: coll) {
        std::cout << "[" << elem.first << "," << elem.second << "] ";
    }
    std::cout << std::endl;
}

#endif