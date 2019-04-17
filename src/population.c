#include "a4.h"
#include <stdlib.h>

PIXEL *generate_random_image(int width, int height, int max_color){
    int numpix;
    int randomrgb1, randomrgb2, randomrgb3;
    int maxcolor = max_color + 1;
    numpix = width * height;
    PIXEL *testarray;    
    testarray = malloc(numpix * sizeof(PIXEL));
    for(int i = 0; i < numpix; i++){
      randomrgb1 = (lrand48()+rand())%(maxcolor);
      randomrgb2 = (lrand48()+rand())%(maxcolor);
      randomrgb3 = (lrand48()+rand())%(maxcolor);     
      (testarray+i)->r = randomrgb1;
      (testarray+i)->g = randomrgb2;
      (testarray+i)->b = randomrgb3;   
    }     
    return testarray;
}

Individual *generate_population(int population_size, int width, int height, int max_color){
  Individual *samplepop;
  samplepop = malloc(population_size * sizeof(Individual));  
  for(int i = 0; i < population_size; i++){
    (samplepop+i)->image.data = generate_random_image(width,height,max_color);    
    (samplepop+i)->image.height = height;
    (samplepop+i)->image.max_color = max_color;
    (samplepop+i)->image.width = width;    
  }
  return samplepop;
}