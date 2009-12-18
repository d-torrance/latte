//will define multivariate polynomial representation, as well as input and output functions
#ifndef POLYREP_H
#define POLYREP_H

#define BLOCK_SIZE 64
#include <NTL/vec_ZZ.h>
#include <NTL/ZZ.h>

NTL_CLIENT

struct eBlock //used to store exponents
{
	eBlock* next;
	vec_ZZ data[BLOCK_SIZE]; //each vec_ZZ contains n elements for an n-variable polynomial
};

struct lBlock //used to store linear forms
{
	lBlock* next;
	vec_ZZ data[BLOCK_SIZE]; //each vec_ZZ contains n elements for an n-variable polynomial
	ZZ degree[BLOCK_SIZE]; //for linear forms only
};

struct cBlock
{
	cBlock* next;
	ZZ data[BLOCK_SIZE];
};

struct polynomial
{
	int termCount, varCount;
	eBlock* eHead; //variable exponents
	cBlock* cHead; //monomial coefficients
};

struct linearPoly
{
	int termCount, varCount;
	lBlock* lHead; //linear forms
	cBlock* cHead; //linear form coefficients
};

void loadPolynomial(polynomial &, const string);
string printPolynomial(const polynomial &);
void destroyPolynomial(polynomial &);
void decompose(polynomial &, linearPoly &, int);
string printForm(const linearPoly &);
void destroyForm(linearPoly &);

#endif
