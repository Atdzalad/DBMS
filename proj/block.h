#pragma once
#include<Windows.h>

#pragma pack(push)
#pragma pack(1)

#define BLOCK_SIZE 512

struct Header					// Block��ͷ
{
    unsigned short type;		// ������(��֪����ʲô�ã�
    unsigned short free;		// ���п�
    unsigned int next;			// ��һ��block���ļ�ƫ����(��̬�ڴ����)�̶�һ��BlockΪ512B
    unsigned short count;		// ��¼��Ŀ
    unsigned short checksum;	// Tcpͷ��У��

  public:
    void Checksum_compute();	// ����checksum
};

#pragma pack(pop)
