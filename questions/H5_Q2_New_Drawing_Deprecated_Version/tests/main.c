#include <check.h>
#include "registers.h"

void init_ports(void);

START_TEST(test_init_ports)
{
    init_ports();
    ck_assert_int_eq(SYSCTL_RCGCGPIO_R, 0b000101);
    ck_assert_int_eq(GPIO_PORTA_DEN_R, 0xFF);
    ck_assert_int_eq(GPIO_PORTC_DEN_R, 0xFF);
    ck_assert_int_eq(GPIO_PORTA_DIR_R, 0b11101011);
    ck_assert_int_eq(GPIO_PORTC_DIR_R, 0b00111001);
}
END_TEST

int main(void)
{
    Suite *s = suite_create("init_ports");

    TCase *tc_init_ports = tcase_create("init_ports");
    tcase_add_test(tc_init_ports, test_init_ports);
    suite_add_tcase(s, tc_init_ports);

    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);

    return 0;
}
