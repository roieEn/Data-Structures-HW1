#pragma once
#include <string>

class Tree{
  protected:
    struct Block{
        Block* right;
        Block* left;
        int data;

        explicit Block(const int data) : right(nullptr), left(nullptr), data(data) {}
        ~Block();
        bool operator >(const Block* comp) const;
    };
    Block* root;

  public:
    Tree() : root(nullptr) {}
    virtual ~Tree();
    int Find(const int id) const;
    virtual void Add(const int data);
    virtual void Remove(const int id);


    //for debug only
  private:
    void PrintInOrder(const Block* root) const;
    void PrintPreOrder(const Block* root) const;
  public:
    void PrintInOrder() const;
    void PrintPreOrder() const;


  protected:
  //helper functions
    static void DeleteSubTree(const Block* curr);
    void Add(int data, Block* root);
    static Block* CreateBlock(int data);
    Block* Traverse(const int id) const;//searching for id in the subtree of root and returning the parent of the last node in the search
    Block* GetBlock(const int id) const;
    Block*& GetPointerToBlock(const int id, Block*& root) const;
    void RemoveLeaf(const int id, Block* toRem);
    void RemoveNodeWithOneChild(const int id, Block* toRem);
    void RemoveNodeWithTwoChildren(Block* toRem);
    Block* GetMin(Block* curr) const;
  };