#include <stdlib.h>
char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);

/**
*get_int - gets char pointer to string with integer
*@num: parameter
*Return: pointer to string.
*/
char *get_int(int num)
{
unsigned int temp;
int length = 0;
long num_l = 0;
char *ret;

temp = _abs(num);
length = get_numbase_len(temp, 10);

if (num < 0 || num_l < 0)
length++;
ret = malloc(length + 1);
if (!ret)
return (NULL);

fill_numbase_buff(temp, 10, ret, length);
if (num < 0 || num_l < 0)
ret[0] = '-';

return (ret);
}

/**
*_abs - computes absolute value of an integer
*@i: parameter
*Return: abs value
*/
unsigned int _abs(int i)
{
if (i < 0)
return (-(unsigned int)i);
return ((unsigned int)i);
}

/**
*get_numbase_len - gets length of buffer
*@num: first parameter
*@base: second parameter
*Return: length of buffer needed
*/
int get_numbase_len(unsigned int num, unsigned int base)
{
int len = 1;
while (num > base - 1)
{
len++;
num /= base;
}
return (len);
}

/**
*fill_numbase_buff - fills buffer with base 36
*@num: first parameter
*@base: second parameter
*@buff: third parameter
*@buff_size: fourth parameter
*Return: no return value.
*/
void fill_numbase_buff(unsigned int num, unsigned int base,
	char *buff, int buff_size)
{
int rem, i = buff_size - 1;

buff[buff_size] = '\0';
while (i >= 0)
{
rem = num % base;
if (rem > 9)
buff[i] = rem + 87;
else
buff[i] = rem + '0';
num /= base;
i--;
}
}
