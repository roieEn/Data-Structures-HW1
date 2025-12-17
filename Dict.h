#include <memory>
#include <exception>
#include "AvlTree.h"
#include "Pair.h"

template <typename T>
class Dict{
  AvlTree<Pair<const int, std::shared_ptr<T>>> tree;

  public:
  Dict() = default;
  ~Dict() = default;
  Dict(Dict& other) = delete;
  Dict& operator=(const Dict& other) = delete;

  void Add(const int id, T& data);
  T& Get(const int id);
  void Remove(const int id);
  const std::shared_ptr<T>& GetShared(const int id) const;

  private:
  Pair<const int, std::shared_ptr<T>> MakeDummy(const int id) const;
};

//puclic funcs:

template<typename T>
void Dict<T>::Add(const int id, T& data){
  std::shared_ptr<T> shared(new T(data));
  Pair<const int, std::shared_ptr<T>> temp = Pair<const int, std::shared_ptr<T>>(id, shared);
  try{
    tree.Add(temp);
  }
  catch(const std::invalid_argument& e){
    shared.reset();
    throw e;
  }
}

template<typename T>
T& Dict<T>::Get(const int id){
  Pair<const int, std::shared_ptr<T>> temp = MakeDummy(id);
  try{
    return tree.Find(temp).second;
  }
  catch(const std::invalid_argument& e){
    throw e;
  }
}

template<typename T>
void Dict<T>::Remove(const int id){
  Pair<const int, std::shared_ptr<T>> temp = MakeDummy(id);
  try{
    tree.Remove(temp);
  }
  catch(const std::invalid_argument& e){
    throw e;
  }
}

template<typename T>
const std::shared_ptr<T>& Dict<T>::GetShared(const int id) const{
  Pair<const int, std::shared_ptr<T>> temp = MakeDummy(id);
  try{
    return tree.Find(temp).second;
  }
  catch(const std::invalid_argument& e){
    throw e;
  }
}

//helper funcs:

template<typename T>
Pair<const int, std::shared_ptr<T>> Dict<T>::MakeDummy(const int id) const{
  std::shared_ptr<T> nullShared = nullptr;
  return Pair<const int, std::shared_ptr<T>>(id, nullShared);
}