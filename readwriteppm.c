#include "a4.h"
#include <stdio.h>
#include <stdlib.h>


PPM_IMAGE *read_ppm(const char *file_name){   
    FILE *fp;    
    fp = fopen(file_name, "r");
    
    if (!fp) {
      fprintf(stderr, "Unable to open file '%s'\n", file_name);
      exit(1);
    }           
    char x, y;    
    int width, height, maxcolor, numpix;
    PPM_IMAGE* sampleimg = malloc(sizeof(PPM_IMAGE));       
    
    fscanf(fp, "%c%c", &y, &x);      
    fscanf(fp, "%d %d %d", &width, &height, &maxcolor); 

    numpix = width * height;
    PIXEL *testarray;
   
    testarray = malloc(numpix * sizeof(PIXEL));
    for(int i = 0; i < numpix; i++){     
      fscanf(fp, "%hhu %hhu %hhu", &testarray[i].r , &testarray[i].g, &testarray[i].b);     
    }        
    fclose(fp);
         
    sampleimg->data = testarray;    
    sampleimg->height = height;
    sampleimg->max_color = maxcolor;
    sampleimg->width = width;  

    return sampleimg;
}

void write_ppm(const char *file_name, const PPM_IMAGE *image){    
    FILE *fp;   
    fp = fopen(file_name, "w");        
    fprintf(fp, "P3\n");    
    fprintf(fp, "%d %d\n%d\n",image->width,image->height, image->max_color);
   
    for(int i = 0; i < image->height; i++){
      for(int j = 0; j < image->width; j++){         
          fprintf(fp, "%hhu %hhu %hhu ", image->data[i*image->width + j].r , image->data[i*image->width + j].g, image->data[i*image->width + j].b);
      }
      fprintf(fp,"\n");
    }
    fclose(fp);
}
