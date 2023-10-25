#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test (my_printf, hex_x_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 123;
    int cnt = my_printf("%x %x", test1, test2);
    cr_assert_stdout_eq_str("2a 7b");
    cr_assert_eq(cnt, 5);
}

Test (my_printf, hex_X_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 123;
    int cnt = my_printf("%X %X", test1, test2);
    cr_assert_stdout_eq_str("2A 7B");
    cr_assert_eq(cnt, 5);
}

Test (my_printf, oct_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 123;
    int cnt = my_printf("%o %o", test1, test2);
    cr_assert_stdout_eq_str("52 173");
    cr_assert_eq(cnt, 6);
}

Test (my_printf, unsigned_test, .init = cr_redirect_stdout)
{
    unsigned int test1 = 42;
    unsigned int test2 = 123;
    int cnt = my_printf("%u %u", test1, test2);
    cr_assert_stdout_eq_str("42 123");
    cr_assert_eq(cnt, 6);
}
