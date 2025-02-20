#ifndef COLORS_H
#define COLORS_H

#ifdef _WIN32
#define CLEAR_SCREEN "cls"  
#else
#define CLEAR_SCREEN "clear"
#endif

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"
#define BG_RED  "\033[41m"
#define ITALIC  "\033[3m"
#define BLINK   "\033[5m"
#define INVERT  "\033[7m"
#define STRIKE  "\033[9m"
#define ITALIC_YELLOW "\033[3;33m"
#define BOLD_RED "\033[1;31m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN "\033[1;36m"
#define BOLD_WHITE "\033[1;37m"

#include<fstream> 
#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include<sstream>
#include<random>
#include<chrono>
#include<ctime>
#include<iomanip>
#include<thread>

#endif  
