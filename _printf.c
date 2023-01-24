#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
        int length;
        int i=0;

        if (format == NULL)
                return (-1);

        while (format && format[i])
        {
                if (format[i] == '\0')
                        return (-1);
                length+=write(1,&format[i],1);
                i++;
        }

        return length;
}
