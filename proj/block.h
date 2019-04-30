#include<Windows.h>
#pragma once
#pragma pack(push)
#pragma pack(1)
#define BLOCK_SIZE 512
struct Header // Block��ͷ
{
    unsigned short type; // ������(��֪����ʲô�ã�
    unsigned short free; // ���п�
    unsigned int next; // ��һ��block���ļ�ƫ����(��̬�ڴ����)�̶�һ��BlockΪ512B
    unsigned short count;     // ��¼��Ŀ
    unsigned short checksum;  // Tcpͷ��У��
    void compute(); // ����checksum
};

struct Record
{
    const static unsigned int size = 12;
    byte* data();
};


struct  Tailer
{
    unsigned short directory[1]; // ���������ļ�¼ƫ��������                                                                             
};

#pragma pack(pop)
struct Block
{
    const static unsigned int size = 512; // ȫ�־�̬����������ھ�̬�����������СΪ512 BYTES
    Header header;            // ͷ��
    Tailer* gettailer();      //��ȡβ��
    BOOL addRecord(Record *buffer);  //��Ӽ�¼
    Record* Serch(byte num);
    BOOL Change(byte num, Record* NewRecord);
    BOOL Del(byte num);
};
