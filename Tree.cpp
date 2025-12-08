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