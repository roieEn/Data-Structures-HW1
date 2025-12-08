#include <string>

class Tree{
  protected:
  class Block{
    Block* right;
    Block* left;
    int data;
    public:
    Block(int data)this.right = null, this.left = null, this.data = data{}
    ~Block(){ //Do Not Delete A Block Unless Both Children Point To Null
      this->left = null; this->right = null;
    }
    Block* GetRight();
    void SetRight(Block*);
    Block* GetLeft();
    void SetLeft(Block*);
    int GetData();
    bool operator >(Block* comp);
  };
  Block* root;

  public:
  Tree() this.root = null{}
  ~Tree();
  int Find(int id);
  virtual void Add(int data);
  virtual Remove(int id);

  //for debug only
  string GetInOrder();
  string GetPreOrder();

  protected:
  void DeleteBlock(Block* curr) noexcept;
  static Block* CreateBlock(int data);
};