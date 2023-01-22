#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>



struct memory
{

    int memory[32];
    int *address[32];

};



 struct cache
{
    int cache[8][4];
    int tag[8];
};
struct memory main_memory();
struct cache direct_mapping();
struct cache associative();
struct cache set();


#endif /*SHELL_h*/
