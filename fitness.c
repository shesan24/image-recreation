
#include <math.h>
#include "a4.h"

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
  double fitness = 0.0;  
  int rdiff, gdiff, bdiff;  
  for(int i = 0; i < image_size; i++){
    rdiff = ((A+i)->r - (B+i)->r);
    gdiff = ((A+i)->g - (B+i)->g);
    bdiff = ((A+i)->b - (B+i)->b);
    fitness += (rdiff*rdiff + gdiff*gdiff + bdiff*bdiff);        
  }
  fitness = sqrt(fitness);
  return fitness;
}

void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){
    int numpix = individual->image.width * individual->image.height;
    double fitness;
    for(int i = 0; i < population_size; i++) {        
        fitness = comp_distance(image,(individual+i)->image.data,numpix);
        (individual+i)->fitness = fitness;        
    }
}

