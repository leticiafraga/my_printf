/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** handle g conversion
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"
#include "include/my_printf.h"

int handle_g(va_list *params, format_string *fs, int upper)
{
    double nb = va_arg(*params, double);
    int exp = get_exp(nb);

    if (fs->precision == -1)
        fs->precision = 6;
    if (fs->precision == 0)
        fs->precision = 1;
    if (exp < -4 || exp >= fs->precision) {
        if (upper) {
            return handle_scientific_not(nb, fs, 'E', 1);
        } else {
            return handle_scientific_not(nb, fs, 'e', 1);
        }
    } else {
        return handle_float_inner(nb, fs, 1);
    }
}

int handle_g_lower(va_list *params, format_string *fs)
{
    return handle_g(params, fs, 0);
}

int handle_g_upper(va_list *params, format_string *fs)
{
    return handle_g(params, fs, 1);
}
