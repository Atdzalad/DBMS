#include"Tree_node.h"

bool Tree_node::If_leaf() 
{
    if (header.type)
        return true;
    else
        return false;
}