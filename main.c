#include <stdio.h>
#include <stdlib.h>
//#include(shell.h)
#include<time.h>




typedef struct
{

        int memory[32];
    int *pc;

}direct1 ;



typedef  struct
{
    int cache[8];
    int *tag;
}point;

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
             point* data = direct_mapping();
             direct1* display = main_memory();
      switch(choice)
      {
      case 1:
          data;
          break;
      case 2:
        //associative();
        break;
      case 3:
        //set();
        break;
      case 4:
        display;
        break;
      case 5:
        default:
            printf("sorry invalid choice\n");




      }

    return 0;
}





int main_memory()
{
// sample memory unit which has some IAS instructions and generated words in hexadecimal form

direct1 copy ;

  int array[]= {00001010 ,00001001 ,00100001 ,00000001};

  printf("ADDRESS       WORDS/INSTRUCTIONS\n");
  for (int i = 0; i < 4; i++)
  {
      copy.memory[i] = array[i];
      copy.pc = &copy.memory[i];
   printf("0x%p         0x%x\n" , copy.pc , copy.memory[i]);
  }

 for (int j = 4; j < 32; j++)
 {
     srand(time(NULL));
     copy.memory[j] = rand() / j;
     copy.pc = &copy.memory[j];
   printf("0x%p        0x%x\n" ,copy.pc , copy.memory[j]);


   }

  return &copy;
}


int direct_mapping()
{
direct1* map = main_memory();

point cache1;
for(int i = 0; i < 8; i++)
{
    cache1.cache[i] = map->memory[i];
    cache1.tag = &cache1.cache[i];
    printf("0x%p     0x%x\n" , cache1.tag , cache1.cache[i]);
}

return &cache1;

}


