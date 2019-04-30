////
// @file file.h
// @brief
// 存储文件
//
// @author zhangzhe
// @email 18909545659@163.com
//
#pragma once

#include <windows.h>
#include <string>

////
// @brief
// 管理文件
//
class File 
{
private:
    HANDLE handle_; // 文件句柄

public:
    File() : handle_(INVALID_HANDLE_VALUE) {}
    int create(LPCSTR path, int size, void* file);
};

