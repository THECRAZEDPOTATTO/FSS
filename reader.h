#pragma once
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <VersionHelpers.h>
#include <cstdio>
#include <tlhelp32.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>
using namespace std;
std::string execute(string cmd,string filename)
{
    std::string file_name = filename;
    std::system((cmd + " > " + file_name).c_str());
    std::ifstream file(file_name);
    return { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() };
}


/*
  ______ _____ _____
 |  ____/ ____/ ____|
 | |__ | (___| (___
 |  __| \___ \\___ \
 | |    ____) |___) |
 |_|   |_____/_____/

*/
