#include <stdio.h>
#include <stdlib.h>
//#include(shell.h)
#include<time.h>

void main_memory();
void direct(int *cache , int length);
void associative();
void set();
typedef struct
{
    int memory[32];

    int *pc;

}direct1 , associative1 , set1;


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
          //direct();
          break;
      case 2:
        associative();
        break;
      case 3:
        set();
        break;
      case 4:
        main_memory();
        break;
      case 5:
        return 0;
        default:
            printf("sorry invalid choice\n");




      }

    return 0;
}





void main_memory()
{
// sample memory unit which has 21 IAS instructions and generated words in hexadecimal form

direct1 main;




 printf("ADDRESS       WORDS/INSTRUCTIONS\n");


 for (int j = 0; j < 32; j++)
 {
     srand(time(NULL));
     main.memory[j] = rand() / j;
     main.pc = &main.memory[j];
  printf("0x%p        0x%x\n" ,main.pc , main.memory[j]);

 }
  return;
}


/*void *direct(int *cache , int length)
{
    int tag;
    int *c = malloc(length * sizeof(int));
    printf("Choose(1 or 2):\n");
    printf("Instruction or Randomly Generated Words\n");
    int select;
    scanf("%d" , &select);
    if (select == 1)
    {
        for (int i = 0; i < length; i++)
        {
            cache[i]= memory[i];
            tag = pc;

        }
    }
    else
    {
        for (int j = 21; j < 32; j++)
        {
            cache[j] = memory2[j];
            tag = pc2;
        }
    }


}*/
void associative()
{

}
void set()
{

}

