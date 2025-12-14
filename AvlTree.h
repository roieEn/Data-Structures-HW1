#include "Tree.h"
#include "Stack.h"

template<typename T>
class AvlTree : public Tree<T, AvlBlock<T>>{
    public:
    AvlTree() : Tree<T, AvlBlock<T>>(){}
    void Add(const T& data) override;
    void Remove(const T& id);

    private:
    AvlBlock<T>* Lroll(AvlBlock<T>* parent);
    AvlBlock<T>* Rroll(AvlBlock<T>* parent);
    AvlBlock<T>* LLroll(AvlBlock<T>*& parant, AvlBlock<T>* child);
    AvlBlock<T>* LRroll(AvlBlock<T>*& parant, AvlBlock<T>* child);
    AvlBlock<T>* RLroll(AvlBlock<T>*& parant, AvlBlock<T>* child);
    AvlBlock<T>* RRroll(AvlBlock<T>*& parant, AvlBlock<T>* child);
    void Reconnect(AvlBlock<T>* block, Stack<AvlBlock<T>*> &path);
};

//public funcs implementation:
template<typename T>
void AvlTree<T>::Add(const T& data) {
    Stack<AvlBlock<T>*> path;
    AvlBlock<T>* curr = this->root;
    if(curr == nullptr){
        this->root = this->CreateBlock(data);
        return;
    }
    while(true){
        if(data < curr->data){
            path.Push(curr);
            if(curr->left == nullptr){
                curr->left = this->CreateBlock(data);
                break;
            }
            curr = curr->left;
            continue;
        }
        if(curr->data < data){
            path.Push(curr);
            if(curr->right == nullptr){
                curr->right = this->CreateBlock(data);
                break;
            }
            curr = curr->right;
            continue;
        }
        throw(std::invalid_argument("id already exists"));
    }
    while(!path.IsEmpty()){
        curr = path.Pop();
        curr->UpdateHight();
        int BF = curr->BF();
        if(BF == 2){
            AvlBlock<T>* newRoot = Lroll(curr);
            Reconnect(newRoot, path);
            continue;
        }
        if(BF == -2){
            AvlBlock<T>* newRoot = Rroll(curr);
            Reconnect(newRoot, path);
            continue;
        }
    }
}


template <typename T>
void AvlTree<T>::Remove(const T& id){
    AvlBlock<T>* curr = this->root;
    while(true){
        if(curr == nullptr)
            throw(std::invalid_argument("data not found"));
        if(id < curr->data){

        }
        if(curr->data < id){

        }
    }
}//ToDo

//private funcs implementation:

template<typename T>
AvlBlock<T>* AvlTree<T>::Lroll(AvlBlock<T>* parant){
    if(parant->left->BF() != -1){
        return LLroll(parant, parant->left);
    }
    else{
        return LRroll(parant, parant->left);
    }
}

template<typename T>
AvlBlock<T>* AvlTree<T>::Rroll(AvlBlock<T>* parant){
    if(parant->right->BF() != 1){
        return RRroll(parant, parant->right);
    }
    else{
        return RLroll(parant, parant->right);
    }
}

template<typename T>
AvlBlock<T>* AvlTree<T>::LLroll(AvlBlock<T>*& parant, AvlBlock<T>*child){
    AvlBlock<T>* temp = parant;
    parant = child;
    temp->left = child->right;
    child->right = temp;
    temp->UpdateHight();
    child->UpdateHight();
    return parant;
}

template<typename T>
AvlBlock<T>* AvlTree<T>::LRroll(AvlBlock<T>*& parant, AvlBlock<T>* child){
    AvlBlock<T>* grandChild = child->right;
    AvlBlock<T>* temp = parant;
    parant = grandChild;
    temp->left = grandChild->right;
    child->right = grandChild->left;
    grandChild->right = temp;
    grandChild->left = child;
    temp->UpdateHight();
    child->UpdateHight();
    grandChild->UpdateHight();
    return parant;
}

template<typename T>
AvlBlock<T>* AvlTree<T>::RLroll(AvlBlock<T>*& parant, AvlBlock<T>* child){
    AvlBlock<T>* grandChild = child->left;
    AvlBlock<T>* temp = parant;
    parant = grandChild;
    temp->right = grandChild->left;
    child->left = grandChild->right;
    grandChild->left = temp;
    grandChild->right = child;
    temp->UpdateHight();
    child->UpdateHight();
    grandChild->UpdateHight();
    return parant;
}

template<typename T>
AvlBlock<T>* AvlTree<T>::RRroll(AvlBlock<T>*& parant, AvlBlock<T>* child){
    AvlBlock<T>* temp = parant;
    parant = child;
    temp->right = child->left;
    child->left = temp;
    temp->UpdateHight();
    child->UpdateHight();
    return parant;
}

template<typename T>
void AvlTree<T>::Reconnect(AvlBlock<T>* block, Stack<AvlBlock<T>*> &path){
    if(path.IsEmpty()){
        this->root = block;
        return;
    }
    AvlBlock<T>* temp = path.Pop();
    path.Push(temp);
    if(block->data < temp->data){
        temp->left = block;
    }
    else{
        temp->right = block;
    }
}