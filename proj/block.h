#pragma once
#include<Windows.h>

#pragma pack(push)
#pragma pack(1)

#define BLOCK_SIZE 512

struct Header					// Block的头
{
    unsigned short type;		// 块类型(不知道有什么用）
    unsigned short free;		// 空闲块
    unsigned int next;			// 下一个block的文件偏移量(静态内存分配)固定一个Block为512B
    unsigned short count;		// 记录数目
    unsigned short checksum;	// Tcp头部校验

  public:
    void Checksum_compute();	// 计算checksum
};

#pragma pack(pop)
