#include <stdio.h>
#include <stdlib.h>
#include<time.h>




 struct memory
{

    int memory[32];
    int *address[32];

};



 struct cache
{
    int cache[8];
    int tag[8];
};
struct memory main_memory();
struct cache direct_mapping();
struct cache associative();

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
        associative();
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
    int array[]= {00001010 ,00001001 ,00100001 ,00000001};  //first four IAS instructions

    printf("ADDRESS             WORDS/INSTRUCTIONS\n");
  for (int i = 0; i < 4; i++)
  {
      copy.memory[i] = array[i];
        copy.address[i] = &copy.memory[i];
           printf("%p         0x%x\n" , copy.address[i] , copy.memory[i]);
  }

    for (int j = 4; j < 32; j++)
   {
     srand(time(NULL));
       copy.memory[j] = rand() / j;
        copy.address[j] = &copy.memory[j];
   printf("%p         0x%x\n" ,copy.address[j] , copy.memory[j]);


    }

         return copy;
         }

struct cache direct_mapping()

{
    struct cache cache1;
     struct memory map = main_memory();
        srand(time(NULL));
          int j = rand() % 26;      //code for random output of j


    printf("current Cache value\n");
    printf("TAG(hex)            WORDS/INSTRUCTIONS\n");
              for(int i = 0 + j; i < 4 + j; i++)
          {
              cache1.cache[i] = map.memory[i];
               cache1.tag[i] = i;
                 printf("%x                   0x%x\n" , cache1.tag[i] , cache1.cache[i] , cache1.cache[i]);
           }
        //hit and miss process
     int input;
      printf("Input the Word to check in the cache\n");
        scanf("%d" , &input);

        int hit;
        while(1){
               for(int k = 0 + j; k < 8 + j;k++)
        {

             if (cache1.cache[k] == input )
             {
               printf("hit at %x with the Word 0x%x\n" , cache1.tag[k] ,cache1.tag[k] );
               printf("Tag number %x with the value %x is Delivered to CPU register\n" , cache1.tag[k] , cache1.cache[k]);
               hit = 1;
               break;

             }
             else
             {
                  printf("missed the value %x at Cache Address 0x%x\n" , input , cache1.tag[k]);
                  hit = 0;
             }

        }
         if (hit == 0)
             {
             printf("searching from Memory..............\n");

            for( int k = 0; k < 32; k++)
                {
                if (input == map.memory[k])
                {

                    printf("found the Word %x in Memory %x\n" , input , map.address[k]);
                    printf("Delivered the Word %x into the CPU Register\n" , input);
                    break;
                }

                else
                {
                    printf("word %x not found in Memory Address %x\n" , input , map.address[k]);

                }

                }
             }
     //adding a word or instruction to the cache from memory
     int add;
     int data[4];
     printf("Add the Word/Instruction to Cache Memory(1 for Yes and 2 for No)\n");
     scanf("%d" , &add);
     int random;
      random = rand() % 4;
     switch(add)
         {
        case 1:
            printf("Enter any data\n");
            for (int i = 4; i < 8; i++)
            {
                printf("Enter %d one\n" ,i );
                scanf("%d" , &data[i]);
                cache1.cache[i + random] = data[i];
                printf("added the Word %x into Cache Address %x\n" , data[i] , cache1.tag[i + random]);
            }
            break;
        case 2:
            break;
        case 3:
        default:
            printf("invalid choice\n");


         }
        }


         return cache1;
}
struct cache associative()
{
    struct cache cache2;
    struct memory map = main_memory();



     return cache2;
}


