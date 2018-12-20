#include <stdlib.h>
#include "a4.h"

void mutate(Individual *individual, double rate){
   int finalrate;
   int randompixel;
   int randomrgb1, randomrgb2, randomrgb3;   
   int imagesize = individual->image.width*individual->image.height;
   int maxcolor = individual->image.max_color + 1;
   finalrate = (rate/100)*imagesize; 
   PIXEL *temparray = individual->image.data; 
   //printf("%d %d %d\n", finalrate,individual[0].image.width,individual[0].image.height);
   for(int i = 0; i < finalrate; i++){
        randompixel = (lrand48())%(imagesize);
        randomrgb1 = (lrand48())%(maxcolor);
        randomrgb2 = (lrand48())%(maxcolor);
        randomrgb3 = (lrand48())%(maxcolor);
        temparray[randompixel].r = randomrgb1;
        temparray[randompixel].g = randomrgb2;
        temparray[randompixel].b = randomrgb3;
   }
}

void mutate_population(Individual *individual, int population_size, double rate){
  int start = population_size/4;
  for(int i = start; i < population_size; i++) {        
        mutate(individual+i ,rate);              
    }
}