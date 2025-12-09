#include "Stack.h"

Stack::Block* Stack::Block::GetNext(){
  return this->next;
}

void Stack::Block::SetNext(Block* next){
  this->next = next;
}

int Stack::Block::GetData(){
  return this->data;
}


Stack::~Stack(){
  while (this->head != nullptr){
    Block* curr = head;
    head = head->GetNext();
    delete curr;
  }
}

void Stack::Push(int data){
  Block* head = new Block(data);
  head->SetNext(this->head);
  this->head = head;
  this->size++;
}

int Stack::Pop(){
  int data = this->head->GetData();
  Block* temp = this->head;
  this->head = this->head->GetNext();
  delete temp;
  this->size--;
  return data;
}

bool Stack::IsEmpty(){
  return this->size == 0;
}