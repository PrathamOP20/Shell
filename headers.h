#ifndef HEADERS_H_
#define HEADERS_H_
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_GREY    "\x1B[90m"
#define COLOR_WHITE  "\x1B[37m"
#define COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include "prompt.h"
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/time.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>
void prompt();
void input_process(char* input);
void warp();
void peek_la();
int compare(const void*a, const void* b);
void peek_no();
void peek_a();
void print_file_info(struct stat entry_stat, const char* filename);
void peek_la_arg();
void peek_l();
void seek(char* val,char x[]);
void seek_f(char* val,char x[]);
void seek_d(char* val,char x[]);
void pastevents_exec(int n);
void pastevents(char* x);
void purge();
void peek_l_arg();
void peek_a_arg();
void proclore(int pid);
void pastevents_print();
char* convert(char* m);
#endif