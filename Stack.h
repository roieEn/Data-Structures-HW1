#pragma once
class Stack{
  class Block{
    Block* next;
    int data;
    public:
    explicit Block(int data): next(nullptr), data(data){}
    Block* GetNext();
    void SetNext(Block* next);
    int GetData();
  };
  Block* head;
  int size;
  public:
  Stack(): head(nullptr), size(0){}
  ~Stack();
  void Push(int data);
  int Pop();
  bool IsEmpty();
};
