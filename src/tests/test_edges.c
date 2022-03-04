#include "./Unity-master/src/unity.h"
#include "../edges.h"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_first_edge_10_70(void)
{
    t_fdf_data fdf_data;

	parser(&fdf_data, "../../test_maps/10-70.fdf");
	transform_nodes(&fdf_data);

    populate_edges(&fdf_data);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes, fdf_data.edges[0].start_node);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + 1, fdf_data.edges[0].end_node);
}

void test_last_edge_10_70(void)
{
    t_fdf_data fdf_data;

	parser(&fdf_data, "../../test_maps/10-70.fdf");
	transform_nodes(&fdf_data);

    populate_edges(&fdf_data);
    // TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + 98, fdf_data.edges[98].start_node);
    // TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + 99, fdf_data.edges[98].end_node);

    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + (fdf_data.number_of_nodes - 2), fdf_data.edges[fdf_data.number_of_edges - 1].start_node);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + (fdf_data.number_of_nodes - 1), fdf_data.edges[fdf_data.number_of_edges - 1].end_node);
}

void test_first_edge_10_2(void)
{
    t_fdf_data fdf_data;

	parser(&fdf_data, "../../test_maps/10-2.fdf");
	transform_nodes(&fdf_data);

    populate_edges(&fdf_data);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes, fdf_data.edges[0].start_node);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + 1, fdf_data.edges[0].end_node);
}

void test_last_edge_10_2(void)
{
    t_fdf_data fdf_data;

	parser(&fdf_data, "../../test_maps/10-2.fdf");
	transform_nodes(&fdf_data);

    populate_edges(&fdf_data);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + (fdf_data.number_of_nodes - 2), fdf_data.edges[fdf_data.number_of_edges - 1].start_node);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + (fdf_data.number_of_nodes - 1), fdf_data.edges[fdf_data.number_of_edges - 1].end_node);
}

void test_first_edge_50_4(void)
{
    t_fdf_data fdf_data;

	parser(&fdf_data, "../../test_maps/50-4.fdf");
	transform_nodes(&fdf_data);

    populate_edges(&fdf_data);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes, fdf_data.edges[0].start_node);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + 1, fdf_data.edges[0].end_node);
}

void test_last_edge_50_4(void)
{
    t_fdf_data fdf_data;

	parser(&fdf_data, "../../test_maps/50-4.fdf");
	transform_nodes(&fdf_data);

    populate_edges(&fdf_data);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + (fdf_data.number_of_nodes - 2), fdf_data.edges[fdf_data.number_of_edges - 1].start_node);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + (fdf_data.number_of_nodes - 1), fdf_data.edges[fdf_data.number_of_edges - 1].end_node);
}

void test_first_edge_100_6(void)
{
    t_fdf_data fdf_data;

	parser(&fdf_data, "../../test_maps/100-6.fdf");
	transform_nodes(&fdf_data);

    populate_edges(&fdf_data);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes, fdf_data.edges[0].start_node);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + 1, fdf_data.edges[0].end_node);
}

void test_last_edge_100_6(void)
{
    t_fdf_data fdf_data;

	parser(&fdf_data, "../../test_maps/100-6.fdf");
	transform_nodes(&fdf_data);

    populate_edges(&fdf_data);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + (fdf_data.number_of_nodes - 2), fdf_data.edges[fdf_data.number_of_edges - 1].start_node);
    TEST_ASSERT_EQUAL_PTR(fdf_data.nodes + (fdf_data.number_of_nodes - 1), fdf_data.edges[fdf_data.number_of_edges - 1].end_node);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_first_edge_10_70);
    RUN_TEST(test_last_edge_10_70);
    RUN_TEST(test_last_edge_50_4);
    RUN_TEST(test_last_edge_100_6);
    return UNITY_END();
}

/*
gcc \
-D UNITY_OUTPUT_COLOR \
-D UNITY_FIXTURE_NO_EXTRAS \
test_edges.c \
./Unity-master/src/unity.c \
../edges.c \
../nodes.c \
../gets.c \
../free_breezy.c \
../libft/libft.a \
../get_next_line/get_next_line.c \
../get_next_line/get_next_line_utils.c \
&& ./a.out
*/
