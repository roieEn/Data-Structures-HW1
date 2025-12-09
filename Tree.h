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
    Block* Traverse(int id);//searching for id in the subtree of root and returning the parent of the last node in the search
    const Block* Traverse(int id) const;//const version


  public:
    Tree() : root(nullptr) {}
    virtual ~Tree();
    const Block* GetRoot() const;
    int Find(int id) const;
    virtual void Add(int data);
    virtual void Remove(int id);

    //for debug only
    void PrintInOrder(const Block* root) const;

    void PrintPreOrder(const Block* root) const;

  protected:
    static void DeleteBlock(const Block* curr);
    static Block* CreateBlock(int data);
};