/*
** EPITECH PROJECT, 2023
** BASIC FLAGS
** File description:
** Basic flags for My printf
*/
#include <stdarg.h>
#include "include/my.h"
#include "include/format.h"

static int validate_hash(format_string *fs, int is_upper)
{
    if (my_strstr(fs->flags, "#")) {
        my_putstr(is_upper ? "0X" : "0x");
        return 2;
    } else
        return 0;
}

static int put_hex(unsigned int n, format_string *fs, int is_upper)
{
    int cnt = 0;

    if (n == 0) {
        my_putchar('0');
        return 1;
    }
    cnt += my_getint_base(n,
        is_upper ? "0123456789ABCDEF" : "0123456789abcdef");
    return cnt;
}

static void put_chars(int n, char c)
{
    for (int i = 0; i < n; i++) {
        my_putchar(c);
    }
}

static int handle_width(int n, int num_len, format_string *fs, int is_upper)
{
    char *right = my_strstr(fs->flags, "-");
    char *zero = my_strstr(fs->flags, "0");

    if (right == 0 && zero == 0) {
        put_chars(fs->width - num_len, ' ');
    }
    validate_hash(fs, is_upper);
    if (right == 0 && zero != 0) {
        put_chars(fs->width - num_len, '0');
    }
    put_hex(n, fs, is_upper);
    if (right != 0) {
        put_chars(fs->width - num_len, ' ');
    }
    return fs->width;
}

static int handle_hex(va_list *args, format_string *fs, int is_upper)
{
    int cnt = 0;
    unsigned int n = va_arg(*args, unsigned int);

    if (n == 0) {
        my_putchar('0');
        return 1;
    }
    if (my_strstr(fs->flags, "#"))
        cnt += 2;
    cnt += my_getint_base_len(n, "0123456789abcdef");
    if (cnt < fs->width) {
        return handle_width(n, cnt, fs, is_upper);
    } else {
        validate_hash(fs, is_upper);
        put_hex(n, fs, is_upper);
        return cnt;
    }
}

int handle_hex_upper(va_list *args, format_string *fs)
{
    return handle_hex(args, fs, 1);
}

int handle_hex_lower(va_list *args, format_string *fs)
{
    return handle_hex(args, fs, 0);
}
