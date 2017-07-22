#include <stdio.h>
#include <stdlib.h>

typedef struct _bitVector bitVector;

typedef char* bv_byte;
typedef unsigned int bv_size;

struct _bitVector
{
	bv_byte byte;
	bv_size size;
};

size_t bv_get_size(bitVector b)
{

}