#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * @args: ...
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
        //va_list args;
        int length;
        int i=0;

        if (format == NULL)
                return (-1);

        //va_start(args, format);

        while (format && format[i])
        {
                if (format[i] == '\0')
                        return (-1);
                length+=write(1,&format[i],1);
                i++;
        }

        //va_end(args);

        return (length);
}
