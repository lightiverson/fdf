# fdf

schrijf een bash script dat over elke map in de directory maps looped
-> voor elke map opent die een terminal window en voert ./fdf uit met de naam van de map als argument

## Todo
3. ~~Fix segfault op pyramide map~~
1. ~~Refactor mlx functies (misschien moet dit later)~~
2. ~~Maak fill matrix functie~~


## Terms
Node: a point represented by three coordinates, x, y and z (can also be called a vertex).
Edge: a line connecting two points.
Face: a surface defined by at least three points.
Wireframe: a shape consisting of just nodes and edges.

matrix_data.matrix is een 2d array waarbij elk element een node is. De eerste node is dus [0, 0] en als het getal waar dat naar wijst 8 is. Dan is x=0, y=0, z=8