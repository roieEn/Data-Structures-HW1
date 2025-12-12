#include<stdexcept>
#include<iostream>

template<typename T>
class Tree{
  protected:
    struct Block{
        Block* right;
        Block* left;
        T data;

        explicit Block(const T& data) : right(nullptr), left(nullptr), data(data) {}
        ~Block() = default;
        bool operator >(const Block* comp) const;
    };
    Block* root;

  public:
    Tree() : root(nullptr) {}
    Tree(const Tree& other);
    virtual ~Tree();
    T& Find(const T& t) const;
    virtual void Add(const T& data);
    virtual void Remove(const T& t);


    //for debug only
  private:
    void PrintInOrder(const Block* root) const;
    void PrintPreOrder(const Block* root) const;
  public:
    void PrintInOrder() const;
    void PrintPreOrder() const;


  protected:
  //helper functions
    Block* CopySubTree(const Block* otherRoot) const;
    static void DeleteSubTree(const Block* curr) noexcept;
    void Add(const T& data, Block* root);
    void Remove(const T& t, Block*& root);
    static Block* CreateBlock(const T& data);
    Block* GetBlock(const T& t) const;
    Block*& GetMin(Block*& curr) const;
  };

//Tree::Block methods

template<typename T>
bool Tree<T>::Block::operator >(const Block* comp) const{
  return this->data > comp->data;
}

//Tree methods
template<typename T>
Tree<T>::Tree(const Tree& other) : root(nullptr) {
  if(other.root == nullptr) return;
  //preorder traversal copy
  this->root = CreateBlock(other.root->data);
  this->root->left = CopySubTree(other.root->left);
  this->root->right = CopySubTree(other.root->right);
}

template<typename T>
Tree<T>::~Tree(){
  if(this->root == nullptr) return;
  DeleteSubTree(this->root);
}

template<typename T>
T& Tree<T>::Find(const T& t) const {
  Block* found = GetBlock(t);
  if(found == nullptr) {
    throw(std::invalid_argument("t not found"));
  }
  return found->data;
}

template<typename T>
void Tree<T>::Add(const T& data){
  if(this->root == nullptr){
    this->root = CreateBlock(data);
    return;
  }
  Add(data, this->root);
}

template<typename T>
void Tree<T>::Remove(const T& t) {
  Remove(t, this->root);
}

//for debug only
template<typename T>
void Tree<T>::PrintInOrder() const {
    PrintInOrder(this->root);
}

template<typename T>
void Tree<T>::PrintPreOrder() const {
    PrintPreOrder(this->root);
}

template<typename T>
void Tree<T>::PrintInOrder(const Block* root) const {
    if(root == nullptr)
      return;
    PrintInOrder(root->left);
    std::cout << root->data << " ";
    PrintInOrder(root->right);
}

template<typename T>
void Tree<T>::PrintPreOrder(const Block* root) const {
    if(root == nullptr)
      return;
    std::cout << root->data << " ";
    PrintPreOrder(root->left);
    PrintPreOrder(root->right);

}

//helper functions
template<typename T>
typename Tree<T>::Block* Tree<T>::CopySubTree(const Block* other) const{
  if(other == nullptr)
    return nullptr;
  Block* newRoot = CreateBlock(other->data);
  newRoot->left = CopySubTree(other->left);
  newRoot->right = CopySubTree(other->right);
  return newRoot;
}

template<typename T>
void Tree<T>::DeleteSubTree(const Block* curr) noexcept{
  if(curr->left != nullptr)
    DeleteSubTree(curr->left);
  if(curr->right != nullptr)
    DeleteSubTree(curr->right);
  delete curr;
}

template<typename T>
void Tree<T>::Add(const T& t, Block* root){
  //left step
  if(t < root->data){
    if(root->left == nullptr){
      root->left = CreateBlock(t);
      return;
    }
  Add(t, root->left);
  return;
  }
  //right step
  if(root->data < t){
    if(root->right == nullptr){
      root->right = CreateBlock(t);
      return;
    }
    Add(t, root->right);
    return;
  }
  // !< and !> -> =
  throw(std::invalid_argument("id already exists"));
}

template<typename T>
void Tree<T>::Remove(const T& t, Block*& root){
  //no block with identifier t
  if(root == nullptr)
    throw(std::invalid_argument("data not found"));
  //recursive step
  if(t < root->data)
    Remove(t, root->left);
  else if(root->data < t)
    Remove(t, root->right);
  else{
    //root is the block to remove

    //1 or less children
    if(root->left == nullptr){
      Block* temp = root;
      root = root->right; 
      //note that root is Block*& so the actual pointer in the parent will be changed
      delete temp;
    }
    else if(root->right == nullptr){
      Block* temp = root;
      root = root->left; 
      //similar to above
      delete temp;
    }
    //2 children
    else{
      //get all needen pointers
      Block*& minRightSubtree = GetMin(root->right);
      Block* minPtr = minRightSubtree;
      Block* temp = root;
      //subsitution
      minRightSubtree = minRightSubtree->right;
      /*
      note that the edge case of minRigtSubTree being root->right is a non-issue
      because minRightSubtree = minRightSubtree->right; means root->right = root->right->right;
      */
      minPtr->right = root->right;
      minPtr->left = root->left;
      root = minPtr;
      //delete old root
      delete temp;
    }
  }
}

template<typename T>
typename Tree<T>::Block* Tree<T>::CreateBlock(const T& data){
  return new Block(data);
}

template<typename T>
typename Tree<T>::Block* Tree<T>::GetBlock(const T& t) const{
  Tree::Block* curr = root;
  while(true){
    if(curr == nullptr)//empty tree
      return nullptr;
    if(t < curr->data)
      curr = curr->left;
    if(curr->data < t)
      curr = curr->right;
    return curr;
  }
}

template<typename T>
typename Tree<T>::Block*& Tree<T>::GetMin(Block*& curr) const{
  if(curr->left == nullptr){
    return curr;
  }
  return GetMin(curr->left);
}