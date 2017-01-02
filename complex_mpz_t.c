#include <complex_mpz_t.h>
#include <stdarg.h>

//these functions assume that rop has been initialized beforehand

//initializes the struct
void mpz_cinit(mpz_t_c op){

	mpz_inits(op.real, op.imag, NULL);

}

//initializes an arbitrary amount of complex mpz ints
void mpz_cinits(int arg_no, ...){

	va_list valist;
	int i;

	va_start(valist, num);

	for(i = 0; i < arg_no; i++){

		mpz_init(va_arg(valist, int));

	}

	va_end(valist);

}

//assigns real and imaginary values to struct
void mpz_cset_val(mpz_t_c rop, mpz_t op1, mpz_t op2){

	mpz_set(rop.real, op1);
	mpz_set(rop.imag, op2);1

}

//sets rop to op
void mpz_cset(mpz_t_c rop, mpz_t_c op){

	mpz_set(rop.real, op.real);
	mpz_set(rop.imag, op.imag);

}

//frees the space occupied by the complex number
void mpz_cclear(mpz_t_c op){

	mpz_clear(op.real);
	mpz_clear(op.imag);

}

//sets rop to op1 + op2
void mpz_cadd(mpz_t_c rop, mpz_t_c op1, mpz_t_c op2){

	mpz_add(rop.real, op1.real, op2.real);
	mpz_add(rop.imag, op1.imag, op2.imag);

}

//sets rop to op1 - op2
void mpz_csub(mpz_t_c rop, mpz_t_c op1, mpz_t_c op2){

	mpz_sub(rop.real, op1.real, op2.real);
	mpz_sub(rop.imag, op1.imag, op2.imag);

}

//sets rop to op1 * op2
void mpz_cmul(mpz_t_c rop, mpz_t_c op1, mpz_t_c op2){

	mpz_t r1, r2, i1, i2;
	mpz_inits(r1, r2, i1, i2, NULL);

	mpz_mul(r1, op1.real, op2.real);
	mpz_mul(r2, op1.imag, op2.imag);
	mpz_mul(i1, op1.imag, op2.real);
	mpz_mul(i2, op1.real, op2.imag);

	mpz_sub(rop.real, r1, r2);
	mpz_add(rop.imag, i1, i2);

}

//sets rop to the conjugate of op
void mpz_cconjugate(mpz_t_c rop, mpz_t_c op){
	
	mpz_t tmp;
	mpz_init(tmp);
	
	mpz_neg(tmp, op.imag);

	mpz_set(rop.real, op.real);
	mpz_set(rop.imag, tmp);

}

//sets rop to the standard norm squared for op
void mpz_cnorm2(mpz_t_c rop, mpz_t_c op){

	mpz_t conjugate;
	mpz_init(conjugate);
	
	mpz_cconjugate(conjugate, op);
	mpz_cmul(rop, conjugate, op);

}

//sets rop to the real part of op
void mpz_creal(mpz_t rop, mpz_t_c op){

	mpz_set(rop, op.real);

}

//sets rop to the imaginary part of op
void mpz_cimag(mpz_t rop, mpz_t_c op){

	mpz_set(rop, op.imag);

}

