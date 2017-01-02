#include <stdio.h>
#include <gmp.h>
#include "complex_mpz_t.h"

void print_complex(mpz_t_c op);

int main(){

	mpz_t r, i;
	mpz_inits(r, i, NULL);
	
	mpz_set_si(r, 3L);
	mpz_set_si(i, 4L);

	//test initialization functions
	mpz_t_c c1, c2, tmp;
	mpz_cinits(3, &c1, &c2, &tmp);
	printf("Initialization successful\n\n");

	//test set functions
	mpz_cset_val(&c1, r, i);
	mpz_cset(&c2, c1);

	printf("The value of c1 is: \n");
	print_complex(c1);
	printf("The values of c2 is: \n");
	print_complex(c2);
	printf("Complex set successful\n\n");

	//test arithmetic
	mpz_cadd(&tmp, c1, c2);
	printf("add result is: \n");
	print_complex(tmp);
	
	mpz_csub(&tmp, c1, c2);
	printf("sub result is: \n");
	print_complex(tmp);

	mpz_cmul(&tmp, c1, c2);
	printf("mul result is: \n");
	print_complex(tmp);

	printf("Arithmetic tests correct\n\n");

	//test conjugate and norm2
	mpz_cconjugate(&tmp, c1);
	printf("Conjugate is: \n");
	print_complex(tmp);
	
	mpz_cnorm2(&tmp, c1);
	printf("Norm squared is: \n");
	print_complex(tmp);

	mpz_cclear(&c1);
	mpz_cclear(&c2);

	mpz_clear(r);
	mpz_clear(i);
	
	printf("\nSuccess!\n");

	return 1;

}


