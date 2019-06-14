#include <stdio.h>
#include <string.h>
int main()
{
     char test[80], blah[80];
     char *sep = "\\/:;=-";
     char *word, *phrase, *brkt, *brkb;

     strcpy(test, "This;is.a:test:of=the/string\\tokenizer-function.");

     for (word = strtok(test, sep, &brkt);
          word;
          word = strtok(NULL, sep, &brkt))
     {
         strcpy(blah, "blah:blat:blab:blag");

         for (phrase = strtok(blah, sep, &brkb);
              phrase;
              phrase = strtok(NULL, sep, &brkb))
         {
             printf("So far we're at %s:%s\n", word, phrase);
         }
     }
}
