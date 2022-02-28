#include "./Unity-master/src/unity.h"
#include "../edges.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_edges_simple(void)
{
    // const char *map_name = "../../test_maps/10-2.fdf";
    // unsigned int columns = count_columns(map_name);
    // unsigned int distance_between_columns = get_distance_between_columns(columns);
    // TEST_ASSERT_EQUAL_UINT(20, distance_between_columns);
    generate_edges();
    TEST_ASSERT_TRUE(1);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_edges_simple);
    return UNITY_END();
}

/*
gcc \
test_edges.c \
./Unity-master/src/unity.c
*/

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