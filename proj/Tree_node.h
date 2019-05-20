#pragma once
#include"Data_block.h"

#define MAXKEY 29
#define MINIKEY 15 

struct Tree_node
{
    Header header;
    long long int  key[MAXKEY];			
    char *pointer[MAXKEY + 1];

	public:

};