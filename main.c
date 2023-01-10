#include <stdio.h>
#include <stdlib.h>
//#include(shell.h)
#include<time.h>




 struct memory
{

        int memory[32];
    int *pc;

} ;



 struct cache
{
    int cache[8];
    int tag[8];
};
struct memory main_memory();
struct cache direct_mapping();

int main()
{


    int choice;
     printf("############################\n");
      printf("#  CACHE MEMORY MAPPING    #\n");
       printf("#                          #\n");
        printf("############################\n");
         printf("choose which kind of mapping technique to proceed:\n ");
          printf("1. Direct Mapping\n");
           printf("2. Associative Mapping\n");
            printf("3. Set-Associative Mapping\n");
             printf("4. display main memory\n");
             scanf("%d" , &choice);


      switch(choice)
      {
      case 1:
          direct_mapping();
          break;
      case 2:
        //associative();
        break;
      case 3:
        //set();
        break;
      case 4:
        main_memory();
        break;
      case 5:
        default:
            printf("sorry invalid choice\n");




      }

    return 0;
}





struct memory main_memory()
{
// sample memory unit which has some IAS instructions and generated words in hexadecimal form

struct memory copy;
  int array[]= {00001010 ,00001001 ,00100001 ,00000001};

  printf("ADDRESS             WORDS/INSTRUCTIONS\n");
  for (int i = 0; i < 4; i++)
  {
      copy.memory[i] = array[i];
      copy.pc = &copy.memory[i];
   printf("%p         0x%x\n" , copy.pc , copy.memory[i]);
  }

 for (int j = 4; j < 32; j++)
 {
     srand(time(NULL));
     copy.memory[j] = rand() / j;
     copy.pc = &copy.memory[j];
   printf("%p         0x%x\n" ,copy.pc , copy.memory[j]);


   }

  return copy;
}

struct cache direct_mapping()

{
    struct cache cache1;
struct memory map = main_memory();
srand(time(NULL));
int j = rand() % 26;
//code for random output of j
printf("current cache value\n");
    printf("TAG(hex)            WORDS/INSTRUCTIONS\n");
for(int i = 0 + j; i < 8 + j; i++)
{
    cache1.cache[i] = map.memory[i];
    cache1.tag[i] = i;
    printf("%x                   0x%x\n" , cache1.tag[i] , cache1.cache[i]);
}
//hit and miss process
int input;
printf("input the word to check in the cache\n");
scanf("%x" , &input);
for(int k = 0 + j; k < 8 + j;k++)
{
    cache1.cache[k] = map.memory[k];
    cache1.tag[k] = k;
 if (cache1.cache[k] == input )
 {
     printf("hit at %x with the word 0x%x\n" , cache1.tag[k] ,cache1.cache[k] );
 }
 }

return cache1;
}


