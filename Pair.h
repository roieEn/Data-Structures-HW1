#include <ostream>

template<typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;

    Pair(const T1& first, const T2& second) : first(first), second(second) {}
    Pair(Const Pair& otehr) = default;
    Pair& operator=(const Pair& other) = delete;
    bool operator<(const Pair& other) const {return this->first < other.first;}
    bool operator>(const Pair& other) const {return this->first > other.first;}
    bool operator==(const Pair& other) const {return this->first == other.first;}
    friend std::ostream& operator<<(std::ostream& out, const Pair&) const{
        out << "(" << first << "," << second << ")";
        return out; 
    }
};