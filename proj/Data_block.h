#pragma once
#include"block.h"

#pragma pack(push)
#pragma pack(1)

struct Record
{
    const static unsigned int size = 12;

  public:
    bool *Get_data();								//获取记录数据
};

struct Tailer
{
    unsigned short directory[1];					// 向上增长的记录偏移量数组
};
#pragma(pop)

struct Data_block
{
    const static unsigned int size =
        512;										// 全局静态变量（存放在静态数据区）块大小为512 BYTES
    Header header;									// 头部

  public:
    Tailer *Get_tailer();                            //获取尾部
    BOOL Add_Record(Record *buffer);                 //添加记录
    Record *Serch_record(bool num);                  //搜索记录
    BOOL Change_record(bool num, Record *NewRecord); //修改记录
    BOOL Update_record(bool num);                    //删除记录
};
