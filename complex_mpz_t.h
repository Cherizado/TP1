#ifndef COMPLEX_MPZ_T
#define COMPLEX_MPZ_T

#include <gmp.h>

typedef struct{

	mpz_t real;
	mpz_t imag;

}mpz_t_c;

void mpz_cinit(mpz_t_c* op);
void mpz_cinits(int arg_no, ...);
void mpz_cset_val(mpz_t_c* rop, mpz_t op1, mpz_t op2);
void mpz_cset(mpz_t_c* rop, mpz_t_c op);
void mpz_cclear(mpz_t_c* op);

void mpz_cadd(mpz_t_c* rop, mpz_t_c op1, mpz_t_c op2);
void mpz_csub(mpz_t_c* rop, mpz_t_c op1, mpz_t_c op2);
void mpz_cmul(mpz_t_c* rop, mpz_t_c op1, mpz_t_c op2);
void mpz_cconjugate(mpz_t_c* rop, mpz_t_c op);
void mpz_cnorm2(mpz_t_c* rop, mpz_t_c op);

void mpz_creal(mpz_t rop, mpz_t_c op);
void mpz_cimag(mpz_t rop, mpz_t_c op);

#endif
