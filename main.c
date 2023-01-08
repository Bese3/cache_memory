#include <stdio.h>
#include <stdlib.h>
//#include(shell.h)
#include<time.h>




typedef struct
{

        int memory[32];
    int *pc;

}direct1 ;

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
             direct1* display = main_memory();
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
// sample memory unit which has 21 IAS instructions and generated words in hexadecimal form

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


void direct_mapping(int *cache , int length)
{
direct1* map = main_memory();
for (int i = 0; i < 32; i++)
{


    printf("%d" , map->memory[i]);
}


}


