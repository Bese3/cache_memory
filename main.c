#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>



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
           printf("%p         0x%x   %d\n" , copy.address[i] , copy.memory[i] , copy.memory[i]);
  }

    for (int j = 4; j < 32; j++)
   {
     srand(time(NULL));
       copy.memory[j] = rand() / j;
        copy.address[j] = &copy.memory[j];
   printf("%p         0x%x   %d\n" ,copy.address[j] , copy.memory[j] , copy.memory[j]);


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
    printf("TAG(hex)            WORDS\n");
              for(int i = 0; i < 4; i++)    //one block of cache is always occupied
          {
              cache1.cache[i] = map.memory[i];
               cache1.tag[i] = i;
                 printf("%x                   0x%x\n" , cache1.tag[i] , cache1.cache[i]);
           }
        //hit and miss process
     int input;
      printf("Input the Word to check in the cache\n");
        scanf("%d" , &input);

        int hit;

               for(int k = 0 ; k < 8;k++)
        {

             if (cache1.cache[k] == input )
             {
               printf("hit at %x with the Word 0x%x\n" , cache1.tag[k] ,cache1.cache[k] );
               printf("Tag number %x (hex) with the value %x is Delivered to CPU register\n" , cache1.tag[k] , cache1.cache[k]);
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

     printf("press keys to Add the Word/Instruction to Cache Memory(1 for Yes and 2 for No)\n");
     scanf("%d" , &add);
     int random = rand() % 4;


     switch(add)
         {
        case 1:

            for(int i = 4; i < 8; i++)
            {
                  printf("Enter the %dth line\n" , i);
                scanf("%d" , &data[i]);
                cache1.cache[i + random] = data[i];
                cache1.tag[i] = i;
                printf("added the Word %x into Cache Address %x\n" , data[i] , cache1.tag[i]);

            }
            printf("CACHE IS FULL\n");
           for(int i = 0; i < 4; i++)
            {
          cache1.cache[i] = 0;
             printf("Cache at %x is erased to %x\n" , i  ,cache1.cache[i]);

            }
            printf("1st block of Cache erased for additional memory \n");
            break;
        case 2:
            break;
        case 3:
        default:
            printf("invalid choice\n");


        }




         return cache1;
}
struct cache associative()
{
    struct cache cache2;

    struct memory map = main_memory();
    //int array[] = {000 , 001 , 010 , 011 , 100 , 101 , 110 , 111};


       srand(time(NULL));
          int j = rand() % 26;
          int k = rand() % 4;      //code for random output of j


    printf("current Cache value\n");
    printf("TAG(hex)            WORDS\n");
              for(int i = 0; i < 4; i++)    //one block of cache is always occupied
              {
              cache2.cache[i] = map.memory[i + j];
               cache2.tag[i] = i;
                 printf("%d                   0x%x\n" , cache2.tag[i] , cache2.cache[i]);

              }
              int up =0;
              int cachevalue = 0;
              for (int i = k; i < k + 5; i++)
              {
                  printf("Enter the %dth Word to insert to a cache\n" , i);
                  scanf("%d" ,&cachevalue);
                  cache2.cache[i] = cachevalue;
                  cache2.tag[i] = i;
                  printf("Cache value updated to %x in the Cache Address %x\n" , cache2.cache[i] , cache2.tag[i]);
                up = i + 1;
              }
              while(up < 8)
              {
                  cache2.cache[up] = 0;
                  cache2.tag[up] = up;
                   up++;
              }
              for (int i = 0; i < 8; i++)
              {
                  printf("In the Address %x Cache Word %x (HEX) is mapped from memory\n" ,cache2.tag[i] , cache2.cache[i] );
              }
              //hit or miss process
                int input;
      printf("Input the Word to check in the cache\n");
        scanf("%d" , &input);

        int hit;

               for(int k = 0 ; k < 8;k++)
        {

             if (cache2.cache[k] == input )
             {
               printf("hit at %x with the Word 0x%x\n" , cache2.tag[k] ,cache2.cache[k] );
               printf("Tag number %x (hex) with the value %x is Delivered to CPU register\n" , cache2.tag[k] , cache2.cache[k]);
               hit = 1;
               break;

             }
             else
             {
                  printf("missed the value %x at Cache Address 0x%x\n" , input , cache2.tag[k]);
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
             // choosing replacement techniques
             int replacement;
             int hl;
             for(int i = 0; i < 8; i++)
             {
                if (cache2.cache[i] != 0)
                      hl = 1;
                else
                    hl = 0;

             }

            if (hl == 1)
            {
                int i = 0;
                printf("Choose replacement technique\n");
                printf("1.Least recently used\n");
                printf("2.Random\n");
                scanf("%d" , &replacement);
            }
            if (replacement == 1)   //least recently used technique
            {
                for (int i = 0; i < k; i++)
                {

                    printf("Replace the Cache value %x with the new value\n" ,cache2.cache[i] );
                    scanf("%x" , cache2.cache[i]);
                    printf("Replaced Successfully\n");
                }
                for(int i = k; i < k + 4; i++)
                {
                    continue;
                }
                for(int i = k + 4; i < 8;i++)
                {

                    printf("Replace the Cache value %x with the new value\n" , cache2.cache[i]);
                    scanf("%x" , cache2.cache[i]);
                    printf("Replaced Successfully\n");
                }
            }
            if (replacement == 2 )
            {
               for(int i = 0;i < 8; i++)
               {
                srand(time(NULL));
                 int random = rand() % 8;
               printf("Replace the Cache value %x with the new value\n" , cache2.cache[random]);
               scanf("%x" , cache2.cache[random]);
                printf("Replaced Successfully\n");
               }
            }
     return cache2;
}


