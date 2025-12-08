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

Tree::Block* Tree::Traverse(const int id, Block *root) {
  Block* curr = root;
  if(curr == nullptr)//empty tree
    return root;
  while(true){
    if(curr->GetData() == id) {//found id
      return curr;
    }
    if(curr->GetData() > id){
      if(curr->GetLeft() != nullptr) {
        curr = curr->GetLeft();
        continue;
      }
      return curr; //id should be to the left of curr but curr doesn't have a left son
    }
    else{
      if(curr->GetRight() != nullptr) {
        curr = curr->GetRight();
        continue;
      }
      return curr; //id should be to the right of curr but curr doesn't have a right son
    }
  }
}

const Tree::Block* Tree::Traverse(const int id,const Block *root) const {
  const Block *curr = root;
  if(curr == nullptr)//empty tree
    return root;
  while(true){
    if(curr->GetData() == id) {
      return curr;
    }
    if(curr->GetData() > id){
      if(curr->GetLeft() != nullptr) {
        curr = curr->GetLeft();
        continue;
      }
      return curr; //id should be to the left of curr but curr doesn't have a left son
    }
    else{
      if(curr->GetRight() != nullptr) {
        curr = curr->GetRight();
        continue;
      }
      return curr; //id should be to the right of curr but curr doesn't have a right son
    }
  }
}


int Tree::Find(const int id) const {
  const Block* found = Traverse(id, this->root);
  if(found->GetData() == id) { //found it
    return found->GetData();
  }
  throw(std::invalid_argument("no such id in tree")); //found the closest node
  // const Block* curr = this->root;
  // while(true){
  //   if(curr == nullptr)
  //     throw(std::invalid_argument("no such id in tree"));
  //   if(curr->GetData() > id){
  //     curr = curr->GetLeft();
  //     continue;
  //   }
  //   if(curr->GetData() < id){
  //     curr = curr->GetLeft();
  //     continue;
  //   }
  //   return curr->GetData();
  // }
}

void Tree::Add(const int data){
  if(this->root == nullptr){
    this->root = CreateBlock(data);
    return;
  }
  Block* found = Traverse(data, this->root);
  if(found->GetData() == data) { //found the data block
    throw(std::invalid_argument("id already exists"));
  }
  if(data < found->GetData()) {//need to add it as a left son because it is smaller
    found->SetLeft(CreateBlock(data));
  }
  if(data > found->GetData()) {//need to add it as a right son because it is bigger
    found->SetRight(CreateBlock(data));
  }

  // while(true){
  //   if(curr->GetData() == data)
  //    throw(std::invalid_argument("id already exists"));
  //   if(curr->GetData() > data){
  //     if(curr->GetLeft() == nullptr){
  //       curr->SetLeft(CreateBlock(data));
  //       return;
  //     }
  //     else{
  //       curr = curr->GetLeft();
  //       continue;
  //     }
  //   }
  //   else{
  //     if(curr->GetRight() == nullptr){
  //       curr->SetRight(CreateBlock(data));
  //       return;
  //     }
  //     else{
  //       curr = curr->GetRight();
  //       continue;
  //     }
  //   }
  // }
}