#include<stdexept>
using Tree.h;

Block* Tree::Block::GetRight(){
  return this->right;
}

Block* Tree::Block::GetLeft(){
  return this->GetLeft;
}

void Tree::Block::SetRight(Block* right){
  this->right = right;
}

void Tree::Block::SetLeft(Block* left){
  this->left = left;
}

int Tree::Block::GetData(){
  return this->data;
}

bool Tree::Block::operator >(Block* comp){
  return this->Data > comp.GetData();
}

Tree::~Tree(){
  if(this->root == null) return;
  DeleteBlock(this->root);
}

void Tree::DeleteBlock(Block* curr){
  if(curr->GetLeft != null)
    deleteBlock(curr->GetLeft());
  if(curr->GetRight != null)
    deleteBlock(curr->GetRight());
  ~curr;
}

int Tree::Find(int id){
  Block* curr = this->root
  while(true){
    if(curr == null)
      throw(std::invalidargument('no such id in tree'));
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

void Tree::Add(int data){
  if(this->root == null){
    this->root = CreateBlock(data);
    return;
  }
  Block* curr = root;
  while(true){
    if(curr->GetData() == data)
     throw(std::invalidargument('id already exists'));
    if(curr->GetData() > data){
      if(curr->GetLeft() == null){
        curr->SetLeft(CreateBlock(data));
        return;
      }
      else{
        curr = curr->GetLeft();
        continue;
      }
    }
    else{
      if(curr->GetRight() == null){
        curr->SetRight(CreateBlock(data));
        return;
      }
      else{
        curr = curr.GetRight();
        continue;
      }
    }
  }
}