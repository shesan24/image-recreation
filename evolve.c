
#include "a4.h"
#include <stdlib.h>
#include <stdio.h>

void free_image(PPM_IMAGE *p){
    free(p->data);   
    free(p);    
}

void free_pop(Individual *pop, int popsize){
  for(int i = 0; i < popsize; i++){
    free((pop+i)->image.data); 
  }
  free(pop);
}

void swap(Individual *indiv1, Individual *indiv2){
     Individual temp;     
     temp = *indiv1;
     *indiv1 = *indiv2;
     *indiv2 = temp;
}

int partition (Individual arr[], int low, int high){ 
	int pivot = arr[high].fitness;
	int i = (low - 1); 
	for (int j = low; j <= high- 1; j++){	
		if (arr[j].fitness <= pivot){ 
			i++;  
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(Individual arr[], int low, int high){ 
	if (low < high){ 
	  int pi = partition(arr, low, high); 	
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

PPM_IMAGE *imagecopy(Individual *org){

    int numpix;
    PPM_IMAGE* sampleimg = malloc(sizeof(PPM_IMAGE));  
    numpix = org->image.width * org->image.height;
    PIXEL *testarray;    
    testarray = malloc(numpix * sizeof(PIXEL));
    for(int i = 0; i < numpix; i++){         
      testarray[i] = org->image.data[i];
    }     
    sampleimg->data = testarray;    
    sampleimg->height = org->image.height;
    sampleimg->max_color = org->image.max_color;
    sampleimg->width = org->image.width; 
    return sampleimg;
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate){
    Individual *indivpop;
    PPM_IMAGE *temp;
    indivpop = generate_population(population_size, image->width,image->height,image->max_color);
    comp_fitness_population(image->data,indivpop,population_size);
    quickSort(indivpop, 0 , population_size-1);
    for(int i = 0; i < num_generations; i++){
        crossover(indivpop, population_size);
        mutate_population(indivpop, population_size, rate);
        comp_fitness_population(image->data, indivpop, population_size);
        quickSort(indivpop, 0, population_size-1); 
        printf("Generation : %d Fitness : %lf\n", i, indivpop[0].fitness);       
    }
    temp = imagecopy(indivpop);
    free_pop(indivpop,population_size);
    return temp;
}