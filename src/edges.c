#include "edges.h"

void generate_edges(void)
{
    t_fdf_data fdf_data;

	parser(&fdf_data, "../test_maps/10-70.fdf");
	printf("fdf_data.rows = %d\n", fdf_data.rows);
	printf("fdf_data.columns = %d\n", fdf_data.columns);
	printf("fdf_data.number_of_nodes = %d\n", fdf_data.number_of_nodes);
	printf("\n");

	transform_nodes(&fdf_data);

    // hoeveel memory heeft edges nodig
    // als je 2 nodes hebt heb je 1 edge
    // maar wat als je een oneven aantal nodes hebt?
    // als je 3 nodes hebt heb je 2 edges
    // als je 4 nodes hebt heb je 3 edges

    t_edge edges[fdf_data.number_of_nodes - 1];
    unsigned int i = 0;
    unsigned int k = 0;
    unsigned int l = 1;
    while (i < fdf_data.number_of_nodes - 1)
    {
        edges[i].start_node = fdf_data.nodes[k];
        edges[i].end_node = fdf_data.nodes[l];
        // printf("edges[%i].start_node = nodes[%i]\n", i, k);
        // printf("edges[%i].end_node = nodes[%i]\n\n", i, l);
        printf("edges[%i].start_node = {x: %i, y: %i, z: %i}\n", i, edges[i].start_node.x, edges[i].start_node.y, edges[i].start_node.z);
        printf("edges[%i].end_node = {x: %i, y: %i, z: %i}\n\n", i, edges[i].end_node.x, edges[i].end_node.y, edges[i].end_node.z);
        k++;
        l++;
        i++;
    }
    // printf("edges[0].start_node = {x: %i, y: %i, z: %i}\n", edges[0].start_node.x, edges[0].start_node.y, edges[0].start_node.z);
    // printf("edges[0].end_node = {x: %i, y: %i, z: %i}\n\n", edges[0].end_node.x, edges[0].end_node.y, edges[0].end_node.z);
    // printf("edges[fdf_data.number_of_nodes - 1 - 1].start_node = {x: %i, y: %i, z: %i}\n", edges[fdf_data.number_of_nodes - 1 - 1].start_node.x, edges[fdf_data.number_of_nodes - 1 - 1].start_node.y, edges[fdf_data.number_of_nodes - 1 - 1].start_node.z);
    // printf("edges[fdf_data.number_of_nodes - 1 - 1].end_node = {x: %i, y: %i, z: %i}\n\n", edges[fdf_data.number_of_nodes - 1 - 1].end_node.x, edges[fdf_data.number_of_nodes - 1 - 1].end_node.y, edges[fdf_data.number_of_nodes - 1 - 1].end_node.z);
}

int main(void)
{
    generate_edges();
    return (0);
}

/*
paint_edges
hoe test je paint edges?
ik wil tussen node[0].x en node[1].x elke waarde pakken en daar een pixel putten.
een functie met als input een edge
een edge is een array van twee nodes
maak een array van edges
loop over array van eges
voor elke edge print je tussen [0] en [1]


edge = [{}, {}]


*/
