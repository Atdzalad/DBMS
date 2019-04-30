////
// @file file.h
// @brief
// �洢�ļ�
//
// @author zhangzhe
// @email 18909545659@163.com
//
#pragma once

#include <windows.h>
#include <string>

////
// @brief
// �����ļ�
//
class File 
{
private:
    HANDLE handle_; // �ļ����

public:
    File() : handle_(INVALID_HANDLE_VALUE) {}
    int create(LPCSTR path, int size, void* file);
};

