#include <stdio.h>
#include "common.c"



main(){

init_rnd((unsigned int)time(NULL));
srand(urnd());
for(;;)
printf("%u\n",urnd()^rand());

}

