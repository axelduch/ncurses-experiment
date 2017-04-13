#include "stdio.h"
#include "stdlib.h"
#include "cell.h"

cell *new_cell(const char *text, unsigned int x, unsigned int y) {
	cell *c = malloc(sizeof *c);
	c->text = strdup(text);
	c->x = x;
	c->y = y;
	return c;
}


void delete_cell(cell *c) {
	if (c != NULL) {
		free(c->text);
		free(c);
		c = NULL;
	}
}

void print_cell(cell *c) {
	if (c == NULL) {
		printf("NULL\n");
		return;
	}
	
	printf("text: %s x:%d y:%d\n", c->text, c->x, c->y);
}
