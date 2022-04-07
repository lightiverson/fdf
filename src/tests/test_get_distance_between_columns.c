#include "./Unity-master/src/unity.h"
#include "../fdf.h"
#include "../gets.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_get_distance_between_columns_10_2(void)
{
    const char *map_name = "../../test_maps/10-2.fdf";
    unsigned int columns = count_columns(map_name);
    unsigned int distance_between_columns = calc_distance_nodes_x(columns);
    TEST_ASSERT_EQUAL_UINT(20, distance_between_columns);
}

void test_get_distance_between_columns_50_4(void)
{
    const char *map_name = "../../test_maps/50-4.fdf";
    unsigned int columns = count_columns(map_name);
    unsigned int distance_between_columns = calc_distance_nodes_x(columns);
    TEST_ASSERT_EQUAL_UINT(16, distance_between_columns);
}

void test_get_distance_between_columns_100_6(void)
{
    const char *map_name = "../../test_maps/100-6.fdf";
    unsigned int columns = count_columns(map_name);
    unsigned int distance_between_columns = calc_distance_nodes_x(columns);
    TEST_ASSERT_EQUAL_UINT(8, distance_between_columns);
}

void test_get_distance_between_columns_julia(void)
{
    const char *map_name = "../../test_maps/julia.fdf";
    unsigned int columns = count_columns(map_name);
    unsigned int distance_between_columns = calc_distance_nodes_x(columns);
    TEST_ASSERT_EQUAL_UINT(1, distance_between_columns);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_get_distance_between_columns_10_2);
    RUN_TEST(test_get_distance_between_columns_50_4);
    RUN_TEST(test_get_distance_between_columns_100_6);
    RUN_TEST(test_get_distance_between_columns_julia);
    return UNITY_END();
}

/*
gcc \
-D UNITY_OUTPUT_COLOR \
-D UNITY_FIXTURE_NO_EXTRAS \
test_get_distance_between_columns.c \
../gets.c \
../fdf.c \
./Unity-master/src/unity.c \
../free_breezy.c \
../libft/libft.a \
../get_next_line/get_next_line.c \
../get_next_line/get_next_line_utils.c \
&& ./a.out
*/