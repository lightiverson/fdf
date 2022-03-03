// #include "edges.h"

// nu wil ik een array van edges creeren op basis van de array van nodes
void generate_edges(void)
{
    t_fdf_data fdf_data;

	parser(&fdf_data, "../test_maps/basictest.fdf");
	printf("fdf_data.rows = %d\n", fdf_data.rows);
	printf("fdf_data.columns = %d\n", fdf_data.columns);
	printf("fdf_data.number_of_nodes = %d\n", fdf_data.number_of_nodes);
	printf("\n");

	transform_nodes(&fdf_data);

    t_edge edges[1];
    // hoeveel memory heeft edges nodig
    // als je 2 nodes hebt heb je 1 edge
    // maar wat als je een oneven aantal nodes hebt?
    // als je 3 nodes hebt heb je 2 edges
    // als je 4 nodes hebt heb je 3 edges

    edges[0].start_node = fdf_data.nodes[0];
    edges[0].end_node = fdf_data.nodes[1];
    printf("edge[0].start_node = {x: %i, y: %i, z: %i}\n", edges[0].start_node.x, edges[0].start_node.y, edges[0].start_node.z);
}

int main(void)
{
    generate_edges();
    return (0);
}

// gcc edges.c nodes.c gets.c free_breezy.c libft/libft.a get_next_line/get_next_line.c get_next_line/get_next_line_utils.c