#ifndef __BIG50_H
#define __BIG50_H

#define MAX50 50
//const int MAX50=50;

typedef struct Integer50
{
  // a dynamically allocated array to hold a 50
  // digit integer, stored in reverse order
  int *digits;
} Integer50;

typedef struct big50RatingStruct{
  char *NID; //pointer to a malloc'ed buffer for the NID
  float degreeOfDifficulty; //1.0 for super easy to 5.0 for insanity++
  float duration; // Hours spent writing, reading,
                  // designing & building the code
} big50RatingStruct;

char *cryptoVariableFilename; // for the filename

int seed;//to seed the RNG or not

int nFib; //control the number of Fibonacci numbers to calculate

Integer50 *cryptoVariable; // 50 digits of used to start the F[x]

Integer50 *hwConfigVariable; // 50 digits of psuedo or real
                             // randomness to start the F[x]
// Functional Prototypes

Integer50 *big50Add(Integer50 *p, Integer50 *q);

Integer50 *big50Destroyer(Integer50 *p);

Integer50 *fibBig50(int n, Integer50 *first, Integer50 *second);

void big50Rating(void);

Integer50 *parseString(char *str);

Integer50 *loadHWConfigVariable(int doSeed);

Integer50 *loadCryptoVariable(char *inputString);

#endif
