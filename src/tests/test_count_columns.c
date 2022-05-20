#include "./Unity-master/src/unity.h"
#include "../structs.h"
#include "../gets.h"
#include "../file_to_str.h"
#include "../utilities.h"
#include "../free_breezy.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_count_columns_10_2(void)
{
    const char *map_name = "../../test_maps/10-2.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(10, columns);
}

void test_count_columns_10_70(void)
{
    const char *map_name = "../../test_maps/10-70.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(10, columns);
}

void test_count_columns_20_60(void)
{
    const char *map_name = "../../test_maps/20-60.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(20, columns);
}

void test_count_columns_42(void)
{
    const char *map_name = "../../test_maps/42.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(19, columns);
}

void test_count_columns_50_4(void)
{
    const char *map_name = "../../test_maps/50-4.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(50, columns);
}

void test_count_columns_100_6(void)
{
    const char *map_name = "../../test_maps/100-6.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(100, columns);
}

void test_count_columns_basictest(void)
{
    const char *map_name = "../../test_maps/basictest.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(11, columns);
}

void test_count_columns_elem_col(void)
{
    const char *map_name = "../../test_maps/elem-col.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(10, columns);
}

void test_count_columns_elem_fract(void)
{
    const char *map_name = "../../test_maps/elem-fract.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(500, columns);
}

void test_count_columns_elem(void)
{
    const char *map_name = "../../test_maps/elem.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(10, columns);
}

void test_count_columns_elem2(void)
{
    const char *map_name = "../../test_maps/elem2.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(20, columns);
}

void test_count_columns_julia(void)
{
    const char *map_name = "../../test_maps/julia.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(500, columns);
}

void test_count_columns_mars(void)
{
    const char *map_name = "../../test_maps/mars.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(200, columns);
}

void test_count_columns_pentenegpos(void)
{
    const char *map_name = "../../test_maps/pentenegpos.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(21, columns);
}

void test_count_columns_plat(void)
{
    const char *map_name = "../../test_maps/plat.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(10, columns);
}

void test_count_columns_pnp_flat(void)
{
    const char *map_name = "../../test_maps/pnp_flat.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(21, columns);
}

void test_count_columns_pylone(void)
{
    const char *map_name = "../../test_maps/pylone.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(48, columns);
}

void test_count_columns_pyra(void)
{
    const char *map_name = "../../test_maps/pyra.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(27, columns);
}

void test_count_columns_pyramide(void)
{
    const char *map_name = "../../test_maps/pyramide.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(27, columns);
}

void test_count_columns_t1(void)
{
    const char *map_name = "../../test_maps/t1.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(200, columns);
}

void test_count_columns_t2(void)
{
    const char *map_name = "../../test_maps/t2.fdf";
    t_fdf_data fdf_data;

    int map_fd = get_map_fd(map_name);
    file_to_str(map_fd, &fdf_data.file_str);
    unsigned int columns = count_columns(fdf_data.file_str);
    TEST_ASSERT_EQUAL_UINT(100, columns);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_count_columns_42);
    RUN_TEST(test_count_columns_10_2);
    RUN_TEST(test_count_columns_10_70);
    RUN_TEST(test_count_columns_20_60);
    RUN_TEST(test_count_columns_50_4);
    RUN_TEST(test_count_columns_100_6);
    RUN_TEST(test_count_columns_basictest);
    RUN_TEST(test_count_columns_elem_col);
    RUN_TEST(test_count_columns_elem_fract);
    RUN_TEST(test_count_columns_elem);
    RUN_TEST(test_count_columns_elem2);
    RUN_TEST(test_count_columns_julia);
    RUN_TEST(test_count_columns_mars);
    RUN_TEST(test_count_columns_pentenegpos);
    RUN_TEST(test_count_columns_plat);
    RUN_TEST(test_count_columns_pnp_flat);
    RUN_TEST(test_count_columns_pylone);
    RUN_TEST(test_count_columns_pyra);
    RUN_TEST(test_count_columns_pyramide);
    RUN_TEST(test_count_columns_t1);
    RUN_TEST(test_count_columns_t2);
    return UNITY_END();
}

/*
gcc \
-D UNITY_OUTPUT_COLOR \
-D UNITY_FIXTURE_NO_EXTRAS \
test_count_columns.c \
../gets.c \
../file_to_str.c \
../utilities.c \
./Unity-master/src/unity.c \
../free_breezy.c \
../libft/libft.a \
&& ./a.out
*/