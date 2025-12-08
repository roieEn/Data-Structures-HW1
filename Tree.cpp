#include <stdexcept>
#include "Tree.h"

Tree::Block::~Block() { //Do Not Delete A Block Unless Both Children Point To Null
    // this->left = nullptr; this->right = nullptr;
    delete right;
    delete left;
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

int Tree::Find(const int id) const {
  const Block* curr = this->root;
  while(true){
    if(curr == nullptr)
      throw(std::invalid_argument("no such id in tree"));
    if(curr->GetData() > id){
      curr = curr->GetLeft();
      continue;
    }
    if(curr->GetData() < id){
      curr = curr->GetLeft();
      continue;
    }
    return curr->GetData();
  }
}

void Tree::Add(const int data){
  if(this->root == nullptr){
    this->root = CreateBlock(data);
    return;
  }
  Block* curr = root;
  while(true){
    if(curr->GetData() == data)
     throw(std::invalid_argument("id already exists"));
    if(curr->GetData() > data){
      if(curr->GetLeft() == nullptr){
        curr->SetLeft(CreateBlock(data));
        return;
      }
      else{
        curr = curr->GetLeft();
        continue;
      }
    }
    else{
      if(curr->GetRight() == nullptr){
        curr->SetRight(CreateBlock(data));
        return;
      }
      else{
        curr = curr->GetRight();
        continue;
      }
    }
  }
}