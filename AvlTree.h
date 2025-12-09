#pragma once
#include "Tree.h"

class AvlTree : public Tree{
public:
    int height = 0;
    void Add(int data) override;
    void Remove(int id) override;
private:
    void Lroll(Block* parent);
    void Rroll(Block* parent);
    void LLroll(Block* grandParent);
    void LRroll(Block* grandParent);
    void RLroll(Block* grandParent);
    void RRroll(Block* grandParent);
};