#pragma once 

#include <iostream>
#include <vector>
#include <string>

#define INFO 0
#define WARING 1
#define FATAL 2 

std::vector<std::string> g_error_level=
{
    "INFO",
    "WARING",
    "FATAL",
};

void Log(int level, std::string message, std::string file, int line)
{
    std::cout << "[ " << g_error_level[level] << " ][ " << message << " ]: " << file << " : " << line << std::endl; 
}

#define LOG(level, message) Log(level, message, __FILE__, __LINE__)
