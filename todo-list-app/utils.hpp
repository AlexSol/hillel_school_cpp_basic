#pragma once
#include <cstdlib>

void ConsoleClear()
{
#if defined _WIN32
    std::system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    std::system("clear");
#elif defined (__APPLE__)
    std::system("clear");
#endif
}