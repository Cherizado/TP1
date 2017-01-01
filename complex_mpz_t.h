#ifndef COMPLEX_MPZ_T
#define COMPLEX_MPZ_T
#else 

#include <gmp.h>

typedef struct{

	mpz_t real;
	mpz_t imag;

}mpz_t_c;


void cadd(mpz_t_c rop, mpz_t_c op1, mpz_t_c op2);
void csubtract(mpz_t_c rop, mpz_t_c op1, mpz_t_c op2);
void cmultiply(mpz_t_c rop, mpz_t_c op1, mpz_t_c op2);
void cconjugate(mpz_t_c rop, mpz_t_c op);
void cnorm(mpz_t_c rop, mpz_t_c op, int squared);

void creal(mpz_t rop, mpz_t_c op);
void cimag(mpz_t rop, mpz_t_c op);

#endif
