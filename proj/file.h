////
// @file file.h
// @brief
// �洢�ļ�
//
// @author niexw
// @email niexiaowen@uestc.edu.cn
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
    int create(std::string path, int size);
};

