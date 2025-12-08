#pragma once
#include <string>

class Tree{
  protected:
  class Block{
      Block* right;
      Block* left;
      int data;
      public:
        explicit Block(const int data) : right(nullptr), left(nullptr), data(data) {}
        ~Block();
        Block* GetRight() const;
        void SetRight(Block*);
        Block* GetLeft() const;
        void SetLeft(Block*);
        int GetData() const;
        bool operator >(const Block* comp) const;
  };
  Block* root;

  public:
    Tree();
    virtual ~Tree();
    int Find(int id) const;
    virtual void Add(int data);
    virtual void Remove(int id);

    //for debug only
    std::string GetInOrder();

    std::string GetPreOrder();

  protected:
    static void DeleteBlock(const Block* curr);
    static Block* CreateBlock(int data);
};