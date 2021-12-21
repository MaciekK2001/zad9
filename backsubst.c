#include "backsubst.h"
/**
 *  * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 *   * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 *    * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 *     */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
        x->data[mat->r-1][0] = b->data[b->r-1][0] / mat->data[mat->r-1][mat->r-1];
        for ( int wiersz = mat->r-2; wiersz >= 0; wiersz--)     {
	        x->data[i][0] = b->data[i][0];
		for( int kolumna = wiersz+1; kolumna < mat->r -1; kolumna++)
		        x->data[wiersz][0] = x->data[wiersz][0] - mat->data[wiersz][kolumna] * x->data[kolumna][0];
        	x->data[wiersz][0] = x->data[wiersz][0] / mat->data[wiersz][wiersz];
		}
	return 0;
}
