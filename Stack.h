#pragma once
template<typename T>
class Stack{
  class Block{
    Block* next;
    T* data;
    public:
    explicit Block(const T& data);
    ~Block();
    Block* GetNext() const; 
    void SetNext(Block* next);
    T GetData() const;
  };
  Block* head;
  int size;
  public:
  Stack(): head(nullptr), size(0){}
  ~Stack();
  void Push(const T& data);
  T Pop();
  bool IsEmpty() const;
};

template<typename T>
Stack<T>::Block::Block(const T& data){
  this->data = new T(data);
  this->next = nullptr;
}

template<typename T>
typename Stack<T>::Block* Stack<T>::Block::GetNext() const{
  return this->next;
}

template<typename T>
Stack<T>::Block::~Block(){
  delete data;
}

template<typename T>
void Stack<T>::Block::SetNext(Block* next){
  this->next = next;
}

template<typename T>
T Stack<T>::Block::GetData () const{
  return *(this->data);
}


template<typename T>
Stack<T>::~Stack(){
  while (this->head != nullptr){
    Block* curr = head;
    head = head->GetNext();
    delete curr;
  }
}

template<typename T>
void Stack<T>::Push(const T& data){
  Block* head = new Block(data);
  head->SetNext(this->head);
  this->head = head;
  this->size++;
}

template<typename T>
T Stack<T>::Pop(){
  T data = this->head->GetData();
  Block* temp = this->head;
  this->head = this->head->GetNext();
  delete temp;
  this->size--;
  return data;
}

template<typename T>
bool Stack<T>::IsEmpty() const{
  return this->size == 0;
}