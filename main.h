#ifndef MAIN_H

#define MAIN_H

#include <stdarg.h>

#include <stdio.h>

#include <unistd.h>


#define UNUSED(x) (void)(x)

#define BUFF_SIZE 1024


/* FLAGS */

#define F_MINUS 1

#define F_PLUS 2

#define F_ZERO 4

#define F_HASH 8

#define F_SPACE 16


/* SIZES */

#define S_LONG 2

#define S_SHORT 1


/**

 * struct fmt - Struct op

 *

 * @fmt: The format.

 * @fn: The function associated.

 */

struct fmt

{

        char fmt;

        int (*fn)(va_list, char[], int, int, int, int);

};



/**

 * typedef struct fmt fmt_t - Struct op

 *

 * @fmt: The format.

 * @fm_t: The function associated.

 */

typedef struct fmt fmt_t;


int _printf(const char *format, ...);

int handle_print(const char *fmt, int *i,

va_list list, char buffer[], int flags, int width, int precision, int size);


/****************** FUNCTIONS ******************/


/* Funtions to print chars and strings */

int print_char(va_list types, char buffer[],

        int flags, int width, int precision, int size);

int print_string(va_list types, char buffer[],

        int flags, int width, int precision, int size);

int print_percent(va_list types, char buffer[],

        int flags, int width, int precision, int size);


/* Functions to print numbers */

int print_int(va_list types, char buffer[],

        int flags, int width, int precision, int size);

int print_binary(va_list types, char buffer[],

        int flags, int width, int precision, int size);

int print_unsigned(va_list types, char buffer[],

        int flags, int width, int precision, int size);

int print_octal(va_list types, char buffer[],

        int flags, int width, int precision, int size);

int print_hexadecimal(va_list types, char buffer[],

        int flags, int width, int precision, int size);

int print_hexa_upper(va_list types, char buffer[],

        int flags, int width, int precision, int size);


int print_hexa(va_list types, char map_to[],

char buffer[], int flags, char flag_ch, int width, int precision, int size);


/* Function to print non printable characters */

int print_non_printable(va_list types, char buffer[],

        int flags, int width, int precision, int size);


/* Funcion to print memory address */

int print_pointer(va_list types, char buffer[],

        int flags, int width, int precision, int size);


/* Funciotns to handle other specifiers */

int get_flags(const char *format, int *i);

int get_width(const char *format, int *i, va_list list);

int get_precision(const char *format, int *i, va_list list);

int get_size(const char *format, int *i);


/*Function to print string in reverse*/

int print_reverse(va_list types, char buffer[],

        int flags, int width, int precision, int size);


/*Function to print a string in rot 13*/

int print_rot13string(va_list types, char buffer[],

        int flags, int width, int precision, int size);


/* width handler */

int handle_write_char(char c, char buffer[],

        int flags, int width, int precision, int size);

int write_number(int is_positive, int ind, char buffer[],

        int flags, int width, int precision, int size);

int write_num(int ind, char bff[], int flags, int width, int precision,

        int length, char padd, char extra_c);

int write_pointer(char buffer[], int ind, int length,

        int width, int flags, char padd, char extra_c, int padd_start);


int write_unsgnd(int is_negative, int ind,

char buffer[],

        int flags, int width, int precision, int size);


/****************** UTILS ******************/

int is_printable(char);

int append_hexa_code(char, char[], int);

int is_digit(char);


long int convert_size_number(long int num, int size);

long int convert_size_unsgnd(unsigned long int num, int size);


#endif /* MAIN_H */




========================================



utils.c CODE




#include "main.h"


/**

 * is_printable - Evaluates if a char is printable

 * @c: Char to be evaluated.

 *

 * Return: 1 if c is printable, 0 otherwise

 */

int is_printable(char c)

{

        if (c >= 32 && c < 127)

                return (1);


        return (0);

}


/**

 * append_hexa_code - Append ascci in hexadecimal code to buffer

 * @buffer: Array of chars.

 * @i: Index at which to start appending.

 * @ascii_code: ASSCI CODE.

 * Return: Always 3

 */

int append_hexa_code(char ascii_code, char buffer[], int i)

{

        char map_to[] = "0123456789ABCDEF";

        /* The hexa format code is always 2 digits long */

        if (ascii_code < 0)

                ascii_code *= -1;


        buffer[i++] = '\\';

        buffer[i++] = 'x';


        buffer[i++] = map_to[ascii_code / 16];

        buffer[i] = map_to[ascii_code % 16];


        return (3);

}


/**

 * is_digit - Verifies if a char is a digit

 * @c: Char to be evaluated

 *

 * Return: 1 if c is a digit, 0 otherwise

 */

int is_digit(char c)

{

        if (c >= '0' && c <= '9')

                return (1);


        return (0);

}


/**

 * convert_size_number - Casts a number to the specified size

 * @num: Number to be casted.

 * @size: Number indicating the type to be casted.

 *

 * Return: Casted value of num

 */

long int convert_size_number(long int num, int size)

{

        if (size == S_LONG)

                return (num);

        else if (size == S_SHORT)

                return ((short)num);


        return ((int)num);

}


/**

 * convert_size_unsgnd - Casts a number to the specified size

 * @num: Number to be casted

 * @size: Number indicating the type to be casted

 *

 * Return: Casted value of num

 */

long int convert_size_unsgnd(unsigned long int num, int size)

{

        if (size == S_LONG)

                return (num);

        else if (size == S_SHORT)

                return ((unsigned short)num);


        return ((unsigned int)num);

}
