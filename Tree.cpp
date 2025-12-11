#include <stdexcept>
#include <iostream>
#include "Tree.h"

//Tree::Block methods

Tree::Block::~Block() { 
  /*
  Notes: 
  we do not delete left and right here to avoid recursive deletions,
  When general tree deletion is needed, it is done in Tree::DeleteSubTree
  Rememer to add delete data when generizing the tree
  */
}

bool Tree::Block::operator >(const Block* comp) const{
  return this->data > comp->data;
}

//Tree methods

Tree::~Tree(){
  if(this->root == nullptr) return;
  DeleteSubTree(this->root);
}

int Tree::Find(const int id) const {
  Block* found = GetBlock(id);
  if(found == nullptr) {
    throw(std::invalid_argument("id not found"));
  }
  return found->data;
}

void Tree::Add(const int data){
  if(this->root == nullptr){
    this->root = CreateBlock(data);
    return;
  }
  Add(data, this->root);
}

void Tree::Remove(const int id) {
  Block* toRem = GetBlock(id);
  if(toRem == nullptr) {
    throw(std::invalid_argument("id not found"));
  }

  if(toRem->left == nullptr && toRem->right == nullptr) {
    //case 1: toRem is a leaf
    RemoveLeaf(id, toRem);
    return;
  }
  if(toRem->left != nullptr && toRem->right != nullptr) {
    //case 2: toRem has two children
    RemoveNodeWithTwoChildren(toRem);
    return;
  }
  //case 3: toRem has one child
  RemoveNodeWithOneChild(id, toRem);
}

//for debug only

void Tree::PrintInOrder() const {
    PrintInOrder(this->root);
}

void Tree::PrintPreOrder() const {
    PrintPreOrder(this->root);
}

void Tree::PrintInOrder(const Block* root) const {
    if(root == nullptr)
      return;
    PrintInOrder(root->left);
    std::cout << root->data << " ";
    PrintInOrder(root->right);
}

void Tree::PrintPreOrder(const Block* root) const {
    if(root == nullptr)
      return;
    std::cout << root->data << " ";
    PrintPreOrder(root->left);
    PrintPreOrder(root->right);

}

//helper functions

void Tree::DeleteSubTree(const Block* curr){
  if(curr->left != nullptr)
    DeleteSubTree(curr->left);
  if(curr->right != nullptr)
    DeleteSubTree(curr->right);
  delete curr;
}

void Tree::Add(int data, Block* root){
  if(root->data == data)
    throw(std::invalid_argument("id already exists"));
  if(root->data > data){
    if(root->left == nullptr){
      root->left = CreateBlock(data);
      return;
    }
    Add(data, root->left);
    return;
  }
  if(root->right == nullptr){
    root->right = CreateBlock(data);
    return;
  }
  Add(data, root->right);
}

Tree::Block* Tree::CreateBlock(int data){
  return new Block(data);
}

Tree::Block* Tree::Traverse(const int id) const{
  Block* curr = root;
  Block* parent = root;
  if(curr == nullptr)//empty tree
    return root;
  while(true){
    if(curr->data == id) {//found id
      return parent;
    }
    if(curr->data > id){
      if(curr->left != nullptr) {
        parent = curr;
        curr = curr->left;
        continue;
      }
      return curr; //id should be to the left of curr but curr doesn't have a left son so curr is the supposed parent
    }
      if(curr->right != nullptr) {
        parent = curr;
        curr = curr->right;
        continue;
      }
      return curr; //id should be to the right of curr but curr doesn't have a right son so curr is the supposed parent
  }
}

Tree::Block* Tree::GetBlock(const int id) const{
  Tree::Block* curr = root;
  while(true){
  if(curr == nullptr)//empty tree
    return nullptr;
  if(curr->data == id) 
    return curr;
  if(curr->data > id)
    curr = curr->left;
  else
    curr = curr->right;
  }
}

Tree::Block*& Tree::GetPointerToBlock(const int id, Block*& root) const{
  if(root == nullptr || root->data == id)
    return root;
  if(root->data > id)
    return GetPointerToBlock(id, root->left);
  return GetPointerToBlock(id, root->right);
}

void Tree::RemoveLeaf(const int id, Block* toRem){
  GetPointerToBlock(id, this->root) = nullptr;
  delete toRem;
}

void Tree::RemoveNodeWithOneChild(const int id, Block* toRem){
  Block* child;
  if(toRem->left != nullptr) {
    child = toRem->left;
  } else {
    child = toRem->right;
  }
  GetPointerToBlock(id, this->root) = child;
  delete toRem;
}

void Tree::RemoveNodeWithTwoChildren(Block* toRem){
  Block* minRightSubtree = GetMin(toRem->right);
  toRem->data = minRightSubtree->data;
  //Remember to set data to nullptr when generalizing the tree
  Remove(minRightSubtree->data); //minRightSubtree is either case 1 or 3
}

Tree::Block* Tree::GetMin(Block* curr) const{
  while(curr->left != nullptr){
    curr = curr->left;
  }
  return curr;
}