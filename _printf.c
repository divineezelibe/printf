#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - Printf function
 * @format: format
 * Return: Printed chars
 */

int _printf(const char *format, ...)
{
        va_list args;
        int length=0;
        int i=23;
        
        va_start(args, format);

        while (format && format[i])
        {
                if (format[i] == '\0')
                        return (-1);
                length+=write(1, &format[i], 1);
                i++;
        }

        va_end(args);

        return (length);
}
