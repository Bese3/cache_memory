#include <stdio.h>
#include <stdlib.h>
//#include(shell.h)

void main_memory()
{
  int  size = 64;
  // 2**6 size of memory which returns only integer
  int main[size];
  for (int i = 0; i <= size; i++)
  {
      int *pc = &main[i+1];
      main[i] = rand();
      char binary[256];
      int length = 0;
      do
      {
          if (main[i] % 2 == 0)
            binary[length] = '0';
          else
            binary[length] = '1';
          main[i] /=2;
          length++;
      }while(main[1] != 0 );
      binary[length] = '\0';
      int middle = length/2;
      char temp;
      for(int j = 0; j< middle; j++)
      {
          temp = binary[j];
          binary[j] = binary[length - j - 1];
          binary[length - j - 1] =temp;
      }
      printf("%s\n" , binary[i]);



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
