//
//  main.c
//  vektoren_einlesen
//
//  Created by Marlon Juntorius on 05.12.22.
//

#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    int n= 3;
    float a[n];
    float b[n];
    
    
    printf("Vektor 1 einlesen: \n");
    for(int i = 0; i< n; i++)
    {
        printf("%d:", i+1);
        scanf("%f", &a[i]);
    }
    
    printf("Vektor 2 einlesen: \n");
    for(int i = 0; i< n; i++)
    {
        printf("%d:", i+1);
        scanf("%f", &b[i]);
    }
    
    
    // Skalarprodukt ohne Pointer
    float produkt =0;
    
    for(int i = 0; i<n ; i++)
    {
        produkt = produkt + (a[i] * b[i]);
    }
    printf("Skalarprodukt (ohne_p): (%.2f) \n", produkt);
    
    
    //Skalarprodukt mit Pointern
    float *p_a = a;                 //Arrays weisen autom. auf Adresse
    float *p_b = b;
    produkt = 0;
    
    for(int i = 0; i<n ; i++)
    {
        produkt += *(p_a +i) * *(p_b +i);
    }
    printf("Skalarprodukt (mit_p): (%.2f) \n", produkt);
    
    
    //Skalarprodukt mit Pointern im heap
    p_a = malloc(n*sizeof(float));          //heap- Speicher im Heap allokieren
    p_b = malloc(n*sizeof(float));
    produkt = 0;
    
    for(int i= 0; i<n ; i++)
    {
        *(p_a +i) = a[i];   //cpy vals of a to heap
        *(p_b +i) = b[i];   //cpy vals of b to heap
        
        produkt += *(p_a +i) * *(p_b +i);
    }
    printf("Skalarprodukt (mit_p_heap): (%.2f) \n", produkt);
    
}
