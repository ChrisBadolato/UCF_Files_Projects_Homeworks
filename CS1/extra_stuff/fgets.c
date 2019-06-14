#include <stdio.h>

int main()
{
   FILE *fp;
   char str[60];

   /* opening file for reading */
   fp = fopen("fgets.txt" , "r");
   if(fp == NULL)
   {
      perror("Error opening file");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL )
   {
      /* writing content to stdout */
      puts(str);
   }
   fclose(fp);

    printf("str: %s", str);
   return(0);
}
