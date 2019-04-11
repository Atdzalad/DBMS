#pragma once

#pragma pack(1)
struct Header
{
    unsigned short type;     // ������
    unsigned short checksum; // Tcpͷ��У��
    unsigned short count;    // ��¼��Ŀ
    unsigned short free;     // ���п�
    unsigned int next;       // ��һ��block���ļ�ƫ����

    unsigned short compute(); // ����checksum 
};

struct Tailer
{
    unsigned short directory[1]; // ���������ļ�¼ƫ��������
};
#pragma pack(pop)

struct Block
{
    static unsigned int size; // ȫ�־�̬����
    Header header;            // ͷ��

    Tailer *getTailer();
    void addRecord(void *buffer, int size);
};
