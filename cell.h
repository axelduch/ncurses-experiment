#ifndef CELL_H
#define CELL_H

typedef struct cell {
	char *text;
	int x;
	int y;
} cell;


cell *new_cell();
void delete_cell(cell *c);
void print_cell(cell *c);

#endif
