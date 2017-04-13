#ifndef GRID_H
#define GRIDH

#include "stdlib.h"
#include "cell.h"

typedef struct grid {
    cell **cells;
    unsigned int width;
    unsigned int height;
} grid;

grid *new_grid();

void print_grid(grid *g);
void delete_grid(grid *g);

#endif
