#include<Windows.h>
#pragma once
#pragma pack(push)
#pragma pack(1)
#define BLOCK_SIZE 512
struct Header // Block的头
{
    unsigned short type; // 块类型(不知道有什么用）
    unsigned short free; // 空闲块
    unsigned int next; // 下一个block的文件偏移量(静态内存分配)固定一个Block为512B
    unsigned short count;     // 记录数目
    unsigned short checksum;  // Tcp头部校验
    void compute(); // 计算checksum
};

struct Record
{
    const static unsigned int size = 12;
    byte* data();
};


struct  Tailer
{
    unsigned short directory[1]; // 向上增长的记录偏移量数组                                                                             
};

#pragma pack(pop)
struct Block
{
    const static unsigned int size = 512; // 全局静态变量（存放在静态数据区）块大小为512 BYTES
    Header header;            // 头部
    Tailer* gettailer();      //获取尾部
    BOOL addRecord(Record *buffer);  //添加记录
    Record* Serch(byte num);
    BOOL Change(byte num, Record* NewRecord);
    BOOL Del(byte num);
};
