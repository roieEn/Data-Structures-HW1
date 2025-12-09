class Stack{
  class Block{
    Block* next;
    int data;
    public:
    Block(): next(nullptr), data(0){}
  };
  Block* head;
  int size;
  public:
  Stack(): head(nullptr), size(0){}
  ~Stack();
  void Push(int data);
  int Pop();
};