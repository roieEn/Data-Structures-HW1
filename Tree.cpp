template<class T>;
class Tree<T>{
  protected:
  class Block<T>{
    Block* right;
    Block* left;
    T* data;
    public:
    Block(T* data)this.right = null, this.left = null, this.data = data{}
    ~Block(){ //Do Not Delete A Block Unless Both Children Point To Null
      delete this.data;
    }
    Block* GetRight();
    void SetRight(Block*);
    Block* GetLeft();
    void SetLeft(Block*);
    T* GetData();
    bool operator >(Block* comp);
  };
  Block* root;

  public:
  Tree() this.root = null{}
  ~Tree();
  Find(int id);
  Add(T* data);
  Remove(int id);
};

template<class T>
Tree<T>::Add(T* data){
  Block* newBlock = new Block(T);
  if(root == null){
    root = newBlock;
    return;
  }
  Block* curr = root;
  while(true){
    if(newBlock > curr){
      if(curr->GetRight == null)
      curr->SetRight(newBlock);
      return;
    }
    else{
      curr = curr->GetRight();
      continue;
    }
    if(curr > newBlock){
      if(curr->GetLeft == null){
        curr->SetLeft(newBlock);
        return;
      }
      else{
        curr = curr->GetLeft();
        continue;
      }
    }
    throw(1);
  }
}