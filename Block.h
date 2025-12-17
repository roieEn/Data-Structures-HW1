template<typename T>
struct BaseBlock{
  BaseBlock* right;
  BaseBlock* left;
  T data;

  explicit BaseBlock(const T& data) : right(nullptr), left(nullptr), data(data) {}
  virtual ~BaseBlock() = default;
  bool operator <(const BaseBlock* comp) const;
};

//BaseBlock methods

template<typename T>
bool BaseBlock<T>::operator <(const BaseBlock* comp) const{
  return this->data < comp->data;
}

template<typename T>
struct AvlBlock{
  AvlBlock* right;
  AvlBlock* left;
  T data;
  int hight;
  explicit AvlBlock(const T& data) : right(nullptr), left(nullptr), data(data), hight(0) {}
  void UpdateHight();
  int BF() const;
  bool operator <(const AvlBlock* comp) const;
};

//AvlBlock methods
template<typename T>
void AvlBlock<T>::UpdateHight(){
  int leftHight = this->left == nullptr ? -1 : left->hight;
  int rightHight = this->right == nullptr ? -1 : right->hight;
  this->hight = 1 + (leftHight > rightHight ? leftHight : rightHight);
}

template<typename T>
int AvlBlock<T>::BF() const{
  int leftHight = this->left == nullptr ? -1 : static_cast<AvlBlock<T>*>(this->left)->hight;
  int rightHight = this->right == nullptr ? -1 : static_cast<AvlBlock<T>*>(this->right)->hight;
  return leftHight - rightHight;
}

template<typename T>
bool AvlBlock<T>::operator<(const AvlBlock* comp)const {
  return this->data < comp->data;
}