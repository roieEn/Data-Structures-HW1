#include <stdexcept>
#include <iostream>
#include "Tree.h"

Tree::Block::~Block() { //Do Not Delete A Block Unless Both Children Point To Null
    // this->left = nullptr; this->right = nullptr;
    delete right;
    delete left;
}

Tree::Block *Tree::CreateBlock(const int data) {
  return new Block(data);
}



Tree::Block* Tree::Block::GetRight() const {
  return this->right;
}

Tree::Block* Tree::Block::GetLeft() const {
  return this->left;
}

void Tree::Block::SetRight(Block* right){
  this->right = right;
}

void Tree::Block::SetLeft(Block* left){
  this->left = left;
}

int Tree::Block::GetData() const {
  return this->data;
}

bool Tree::Block::operator >(const Block* comp) const{
  return this->data > comp->GetData();
}

Tree::~Tree(){
  if(this->root == nullptr) return;
  DeleteBlock(this->root);
}



void Tree::DeleteBlock(const Block* curr){
  // if(curr->GetLeft() != nullptr)
  //   DeleteBlock(curr->GetLeft());
  // if(curr->GetRight != nullptr)
  //   DeleteBlock(curr->GetRight());
  // ~curr;
  delete curr;
}

Tree::Block* Tree::Traverse(const int id) {
  Block* curr = root;
  Block* parent = root;
  if(curr == nullptr)//empty tree
    return root;
  while(true){
    if(curr->GetData() == id) {//found id
      return parent;
    }
    if(curr->GetData() > id){
      if(curr->GetLeft() != nullptr) {
        parent = curr;
        curr = curr->GetLeft();
        continue;
      }
      return curr; //id should be to the left of curr but curr doesn't have a left son so curr is the supposed parent
    }
      if(curr->GetRight() != nullptr) {
        parent = curr;
        curr = curr->GetRight();
        continue;
      }
      return curr; //id should be to the right of curr but curr doesn't have a right son so curr is the supposed parent
  }
}

const Tree::Block* Tree::Traverse(const int id) const {
  const Block* curr = root;
  const Block* parent = root;
  if(curr == nullptr)//empty tree
    return root;
  while(true){
    if(curr->GetData() == id) {//found id
      return parent;
    }
    if(curr->GetData() > id){
      if(curr->GetLeft() != nullptr) {
        parent = curr;
        curr = curr->GetLeft();
        continue;
      }
      return curr; //id should be to the left of curr but curr doesn't have a left son so curr is the supposed parent
    }
      if(curr->GetRight() != nullptr) {
        parent = curr;
        curr = curr->GetRight();
        continue;
      }
      return curr; //id should be to the right of curr but curr doesn't have a right son so curr is the supposed parent
  }
}

int Tree::Find(const int id) const {
  const Block* found = Traverse(id);
  if(id < found->GetData()) {
    if(id == found->GetLeft()->GetData()) {
      return found->GetLeft()->GetData();
    }
    throw(std::invalid_argument("no such id in tree")); //found the closest node
  }
  if(id > found->GetData()) {
    if(id == found->GetRight()->GetData()) {
      return found->GetRight()->GetData();
    }
     throw(std::invalid_argument("no such id in tree")); //found the closest node
  }
  if(id == found->GetData()) {
    throw std::runtime_error("traverse returned id, error");//not supposed to happen.
  }
  throw std::runtime_error("couldn't compare id to found->GetData()");
}

void Tree::Add(const int data){
  Block* found = Traverse(data); //supposed to be the parent of the new block
  if(found->GetRight() != nullptr || found->GetRight() != nullptr) { //found is a parent of a real block, so one of his son is data
    throw(std::invalid_argument("id already exists"));
  }
  if(data < found->GetData()) {//need to add it as a left son because it is smaller
    found->SetLeft(CreateBlock(data));
  }
  if(data > found->GetData()) {//need to add it as a right son because it is bigger
    found->SetRight(CreateBlock(data));
  }
}

void Tree::Remove(const int id) {
  const Block* found = Traverse(id);
  if(found->GetRight()->GetData() == id) {
    DeleteBlock(found);
    return;
  }
  if(found->GetLeft()->GetData() == id) {
    DeleteBlock(found);
    return;
  }
  throw(std::invalid_argument("no such id in tree"));
}




void Tree::PrintInOrder(const Block* root) const {
    if(root == nullptr)
      return;
    if(root->GetLeft() != nullptr) {
      return PrintInOrder(root->GetLeft());
    }
    else {
      std::cout << root->GetData() << std::endl;
      PrintInOrder(root->GetRight());
    }
}


void Tree::PrintPreOrder(const Block* root) {
    if(root == nullptr)
      return;
    std::cout << root->GetData() << std::endl;
    if(root->GetLeft() != nullptr) {
      return PrintPreOrder(root->GetLeft());
    }
    else {
      PrintPreOrder(root->GetRight());
    }

}
