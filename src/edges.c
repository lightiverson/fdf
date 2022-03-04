#include "edges.h"

t_edge *calloc_edges(unsigned int number_of_edges)
{
    t_edge *edges;

    edges = calloc(number_of_edges, sizeof(*edges));
    if (edges == NULL)
    {
        perror("Error: malloc() ");
        exit(EXIT_FAILURE);
    }
    return (edges);
}

void populate_edges(t_fdf_data *fdf_data)
{
    unsigned int i;

    i = 0;
    fdf_data->edges = calloc_edges(fdf_data->number_of_edges);
    while (i < fdf_data->number_of_edges)
    {
        fdf_data->edges[i].start_node = fdf_data->nodes + i;
        fdf_data->edges[i].end_node = fdf_data->nodes + i + 1;
        i++;
    }
}