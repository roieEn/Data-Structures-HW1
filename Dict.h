#include <memory>

template <typename T>
class Dict{
  AvlTree<Pair<const int, shared_ptr<T>> tree;

  public:
  Dict() = default;
  ~Dict() = default;
  Dict(Dict& other) = delete;
  operator=() = delete;

  void Add(const int id, T& data);
  T& Get(const int id);
  void Remove(const int id);
  const Pair<const int, shared_ptr<T>>& GetPair(const int id);
}