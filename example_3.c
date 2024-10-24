#include <stdio.h>
#include <string.h>

#define STR_SIZE 20

void start() {}
void pause() {}
void raw_copy(char *, char *); /* avoid stack replacement */

int *bad_int_example(int value)
{
   int local = value;
   int *other = &local;

   return other;
}

char *bad_array_example(char *input)
{
   char copy[STR_SIZE];

   strncpy(copy, input, STR_SIZE - 1);
   copy[STR_SIZE - 1] = '\0';

   return copy;
}

void example1()
{
   int *bad_int_ptr1;
   int *bad_int_ptr2;
   int one;
   int two;

   printf("Example 1\n");

   bad_int_ptr1 = bad_int_example(99);
   bad_int_ptr2 = bad_int_example(357);

   one = *bad_int_ptr1;
   two = *bad_int_ptr2;

   printf("integer 1: %d\n", one);
   printf("integer 2: %d\n", two);
}

void example2()
{
   char bad_string1[STR_SIZE];
   char bad_string2[STR_SIZE];
   char *bad_string_result1;
   char *bad_string_result2;

   printf("Example 2\n");

   bad_string_result1 = bad_array_example("first");
   bad_string_result2 = bad_array_example("second");

   raw_copy(bad_string1, bad_string_result1);
   raw_copy(bad_string2, bad_string_result2);   

   printf("string 1: %s\n", bad_string1);
   printf("string 2: %s\n", bad_string2);
}

int main(void)
{
   example1();

   printf("\n");

   example2();

   printf("\n");
   
   return 0;
}

void raw_copy(char *dst, char *src)
{
   while ((*dst++ = *src++));
}
