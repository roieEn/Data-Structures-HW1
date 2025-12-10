template<typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;

    Pair(const T1& first, const T2& second) : first(first), second(second) {}
};