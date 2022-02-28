#ifndef EDGES_H
# define EDGES_H

#include "nodes.h"
#include "fdf.h"

typedef struct s_edge {
    t_node start_node;
    t_node end_node;
} t_edge;

void generate_edges(void);

#endif /* EDGES_H */