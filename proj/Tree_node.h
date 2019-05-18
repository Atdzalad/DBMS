#pragma once
#include"Data_block.h"

#define MAXKEY 99
#define MINIKEY 50 

struct Tree_node
{
    Header header;
    char key[MAXKEY];			
    char *pointer[MAXKEY + 1];

	public:

};