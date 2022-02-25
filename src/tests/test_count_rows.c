#include "./Unity-master/src/unity.h"
#include "../gets.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_count_rows_10_2(void)
{
    const char *map_name = "../../test_maps/10-2.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(10, rows);
}

void test_count_rows_10_70(void)
{
    const char *map_name = "../../test_maps/10-70.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(10, rows);
}

void test_count_rows_20_60(void)
{
    const char *map_name = "../../test_maps/20-60.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(20, rows);
}

void test_count_rows_42(void)
{
    const char *map_name = "../../test_maps/42.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(11, rows);
}

void test_count_rows_50_4(void)
{
    const char *map_name = "../../test_maps/50-4.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(50, rows);
}

void test_count_rows_100_6(void)
{
    const char *map_name = "../../test_maps/100-6.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(100, rows);
}

void test_count_rows_basictest(void)
{
    const char *map_name = "../../test_maps/basictest.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(9, rows);
}

void test_count_rows_elem_col(void)
{
    const char *map_name = "../../test_maps/elem-col.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(10, rows);
}

void test_count_rows_elem_fract(void)
{
    const char *map_name = "../../test_maps/elem-fract.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(500, rows);
}

void test_count_rows_elem(void)
{
    const char *map_name = "../../test_maps/elem.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(10, rows);
}

void test_count_rows_elem2(void)
{
    const char *map_name = "../../test_maps/elem2.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(20, rows);
}

void test_count_rows_julia(void)
{
    const char *map_name = "../../test_maps/julia.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(500, rows);
}

void test_count_rows_mars(void)
{
    const char *map_name = "../../test_maps/mars.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(116, rows);
}

void test_count_rows_pentenegpos(void)
{
    const char *map_name = "../../test_maps/pentenegpos.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(9, rows);
}

void test_count_rows_plat(void)
{
    const char *map_name = "../../test_maps/plat.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(14, rows);
}

void test_count_rows_pnp_flat(void)
{
    const char *map_name = "../../test_maps/pnp_flat.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(9, rows);
}

void test_count_rows_pylone(void)
{
    const char *map_name = "../../test_maps/pylone.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(47, rows);
}

void test_count_rows_pyra(void)
{
    const char *map_name = "../../test_maps/pyra.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(27, rows);
}

void test_count_rows_pyramide(void)
{
    const char *map_name = "../../test_maps/pyramide.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(34, rows);
}

void test_count_rows_t1(void)
{
    const char *map_name = "../../test_maps/t1.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(200, rows);
}

void test_count_rows_t2(void)
{
    const char *map_name = "../../test_maps/t2.fdf";
    unsigned int rows = count_rows(map_name);
    TEST_ASSERT_EQUAL_UINT(100, rows);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_count_rows_10_2);
    RUN_TEST(test_count_rows_10_70);
    RUN_TEST(test_count_rows_20_60);
    RUN_TEST(test_count_rows_42);
    RUN_TEST(test_count_rows_50_4);
    RUN_TEST(test_count_rows_100_6);
    RUN_TEST(test_count_rows_basictest);
    RUN_TEST(test_count_rows_elem_col);
    RUN_TEST(test_count_rows_elem_fract);
    RUN_TEST(test_count_rows_elem);
    RUN_TEST(test_count_rows_elem2);
    RUN_TEST(test_count_rows_julia);
    RUN_TEST(test_count_rows_mars);
    RUN_TEST(test_count_rows_pentenegpos);
    RUN_TEST(test_count_rows_plat);
    RUN_TEST(test_count_rows_pnp_flat);
    RUN_TEST(test_count_rows_pylone);
    RUN_TEST(test_count_rows_pyra);
    RUN_TEST(test_count_rows_pyramide);
    RUN_TEST(test_count_rows_t1);
    RUN_TEST(test_count_rows_t2);
    return UNITY_END();
}

/*
gcc \
-D UNITY_OUTPUT_COLOR \
-D UNITY_FIXTURE_NO_EXTRAS \
test_count_rows.c \
../gets.c \
./Unity-master/src/unity.c \
../free_breezy.c \
../libft/libft.a \
../get_next_line/get_next_line.c \
../get_next_line/get_next_line_utils.c \
&& ./a.out
*/