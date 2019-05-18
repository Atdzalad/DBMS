#pragma once
#include "block.h"
#include "Tree_node.h"

struct Bplus_tree
{
    Tree_node *root;

  public:
    bool Node_split(Tree_node* father, int aim);
    bool Insert_key(char key,  Data_block *datapointer);
    bool Delete_key(char key);
    bool Serch_key(char key);
    bool Insert_nofull(Tree_node* node, char key, Data_block *datapointer);
};