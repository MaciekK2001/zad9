#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    
	double wspolczynnik;

       for(int k = 0; k < mat->c-1; k++)
	   {
		   for(int w=k+1; w<mat->c; w++)
		   {
			   if(mat->data[k][k] == 0.0)
			   {
			     printf("ERROR: dzielenie przez 0\n");
			     return 1;
			   }

			   wspolczynnik = mat->data[w][k]/mat->data[k][k]; 
               
			   for(int i = 0; i < mat->c; i++)
			   {
                  mat->data[w][i]-=wspolczynnik*mat->data[k][i];
			   }
			   b->data[w][0]-=(wspolczynnik)*(b->data[k][0]);

                 
		   }
	   }
	

		return 0;
}

