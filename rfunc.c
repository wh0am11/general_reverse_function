/*
###############################
#
# Author: wh0am1
# Description: Given a number as an argument, we can reverse it using an equation
# Date: 7-19-17
#
###############################
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

unsigned int convert_to_int(char* str);
unsigned int gr2func(unsigned int p);
unsigned int grfunc(unsigned int p,unsigned int n);


int main(int argc,char* argv[]) {

if (argc == 3) {

unsigned int input;
unsigned int n;
unsigned int result;

input = convert_to_int(argv[1]);
n = convert_to_int(argv[2]);

if (input == 0 || n == 0) {

fprintf(stderr,"Invalid argument was provided, computation couldn't be complete\n");
return -1;

}

result = grfunc(input,n);

if (result == 0) {

fprintf(stderr,"Invalid argument was provided, computation couldn't be complete\n");
return -1;

}
else printf("%d\n",result);

}
else fprintf(stderr,"Invalid arguments provided\n");


return 0;

}


unsigned int convert_to_int(char* str) {

/* Convert to integer */

unsigned int r;

r = (unsigned int)strtol(str,NULL,10);

if (errno == ERANGE || (errno == EINVAL && r == 0)) {

perror("Error");
return 0;

}

return r;

}

unsigned int grfunc(unsigned int p,unsigned int n) {

/* Reverses number with n digits (as long as n > 2) */

if (n < 2) return 0;
else if (n == 2) return gr2func(p);

unsigned int q;
unsigned int exponent;

exponent = (unsigned int)pow(10.0,(double)(n-1));

q = 10*(grfunc((p % exponent),n-1)) + ((p - (p % exponent))/exponent);

return q;


}

unsigned int gr2func(unsigned int p) {

/* Reverses number with 2 digits (basis of the above function) */

if (p < 10 || p > 99) return 0;

unsigned int q;

q = (p + 99*(p % 10))/10;

return q;

}
