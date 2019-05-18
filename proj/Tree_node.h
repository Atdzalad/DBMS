#pragma once
#include"block.h"

#define MAXKEY 99

struct Tree_node
{
    Header header;
    char key[MAXKEY];
    char pointer[MAXKEY + 1];

  public:
    bool If_leaf();
};