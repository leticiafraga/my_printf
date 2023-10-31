/*
** EPITECH PROJECT, 2023
** e_flag
** File description:
** e_flag for my_printf
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"

int get_exp(double nb)
{
    int exp = 0;
    int rest = 1;
    double neg_rest;

    nb = nb < 0 ? nb * -1 : nb;
    if (nb >= 1) {
        rest = nb / 10;
        while (rest != 0) {
            exp++;
            rest = rest / 10;
        }
    }
    if (nb < 1) {
        neg_rest = nb;
        while (neg_rest < 1) {
            exp--;
            neg_rest = neg_rest * 10;
        }
    }
    return exp;
}

static void print_mantissa(double nb, int exp)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (exp < 0) {
        for (int i = 0; i > exp; i--) {
            nb = nb * 10;
        }
    } else {
        for (int i = 0; i < exp; i++) {
            nb = nb / 10;
        }
    }
    my_putfloat(nb, 6);
}

static void print_exp(int exp, char e)
{
    my_putchar(e);
    if (exp < 0) {
        my_putchar('-');
        exp = exp * -1;
    } else {
        my_putchar('+');
    }
    if (exp < 10) {
        my_putchar('0');
    }
    my_put_nbr(exp);
}

static int handle_scientific_not(va_list *params, format_string *fs, char e)
{
    double nb = va_arg(*params, double);
    int exp;

    exp = get_exp(nb);
    print_mantissa(nb, exp);
    print_exp(exp, e);
    return 0;
}

int handle_scientific_not_lower(va_list *params, format_string *fs)
{
    return handle_scientific_not(params, fs, 'e');
}

int handle_scientific_not_upper(va_list *params, format_string *fs)
{
    return handle_scientific_not(params, fs, 'E');
}