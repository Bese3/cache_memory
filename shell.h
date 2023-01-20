#ifndef SHELL_H
#define SHELL_H
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
