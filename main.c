#include <stdio.h>
#include <stdlib.h>
//#include(shell.h)
#include<time.h>

void main_memory()
{
 int instruct[20] = {00001010 ,00001001 ,00100001 ,00000001 ,00000010 ,00000011 ,00000100 ,00001101 ,00001110 ,00001111 ,00010000 ,00000101 ,00000111 ,00000110 ,00001000 , 00001011 , 00001100 ,00010100 , 00010101 , 00010010 , 00010011};
 int size = 64;
 int main[size];
 int i;
  for(i = 0; i < 21; i++)
  {
   main[i] = instruct[i]; // mapping all instruction in memory
   int *pc = main[i + 1]; //program counter in CPU has always the next instruction placed
   printf("%d\n" , main[i]);
  } 
  int length = 0;
  int binary[size - 20];
  for(int j = 21; j < 64; i++)
  {
    srand(time(NULL));
   main[j] = rand();
   do
   {
    if (main[j] % 2 == 0)
     binary[length] = 0;
     else
     binary[length] = 1;
     main[j] = main[j] / 2;
     length++;


   } while ({main[j] != 0});
   printf("%d\n" , binary[j]);
   


  }

  



}



void direct()
{

}
void associative()
{

}
void set()
{

}

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
          direct();
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
