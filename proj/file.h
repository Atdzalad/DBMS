////
// @file file.h
// @brief
// 存储文件
//
// @author niexw
// @email niexiaowen@uestc.edu.cn
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
    int create(std::string path, int size);
};

