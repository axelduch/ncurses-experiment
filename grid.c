#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "stdint.h"
#include "ncurses.h"
#include "cell.h"
#include "grid.h"

void create_cells(grid *g) {
    if (g == NULL) {
        return;
    }

    g->cells = malloc(sizeof *(g->cells) * g->width * g->height);

    if (g->cells == NULL) {
        return;
    }

    for (unsigned int y = 0; y < g->height; y++) {
        for (unsigned int x = 0; x < g->width; x++) {
            size_t loc = x + y * g->width;
            g->cells[loc] = new_cell("yo", x, y);

            cell *c = g->cells[loc];
            c->x = x;
            c->y = y;
        }
    }
}

grid *new_grid(unsigned int width, unsigned int height) {
    grid *g = malloc(sizeof *g);

    g->width = width;
    g->height = height;

    create_cells(g);

    return g;
}


void print_n_times_str(unsigned int times, const char *chr) {
    for (unsigned int i = 0; i < times; i++) {
        printw("%s", chr);
    }
}

char *compute_border_str(grid *g) {
    unsigned int num_cells = g->width * g->height;
    unsigned int max_digits = 1 + ((unsigned int) log10(num_cells));

    size_t border_suffix_len = max_digits;
    char *border_str = malloc((4 + border_suffix_len) * sizeof *border_str);
    char border_str_suffix[border_suffix_len + 1];

    for (size_t i = 0; i < border_suffix_len; i++) {
        border_str_suffix[i] = '-';
    }

    border_str_suffix[border_suffix_len] = '\0';

    snprintf(border_str, 2 + border_suffix_len + 1, "+-%s", border_str_suffix);

    return border_str;
}

void print_grid(grid *g) {
    if (g == NULL || g->cells == NULL) {
        printw("empty, width: %d, height: %d\n", g->width, g->height);
    }


    unsigned int num_cells = g->width * g->height;
    unsigned int max_digits = 1 + ((unsigned int) log10(num_cells));
    unsigned int max_pad = 1 + max_digits;

    char *border_str = compute_border_str(g);

    print_n_times_str(g->width, border_str);
    printw("+\n");


    for (unsigned int y = 0; y < g->height; y++) {
        for (unsigned int x = 0; x < g->width; x++) {
            unsigned int loc = x + y * g->width;
            unsigned int pad_size = max_pad - (1 + (unsigned int)log10(loc));

            cell *c = g->cells[loc];

            printw("|");
            printw("%d", x + y * g->width);
            print_n_times_str(pad_size, " ");


            if (x + 1 == g->width) {
                printw("|\n");
                print_n_times_str(g->width, border_str);
                printw("+\n");
            }
        }
    }
}


void delete_cells(grid *g) {
    if (g == NULL || g->cells == NULL) {
        return;
    }

    for (unsigned int y = 0; y < g->height; y++) {
        for (unsigned int x = 0; x < g->width; x++) {
            delete_cell(g->cells[x + y * g->width]);
        }
    }

    g->cells = NULL;
}


void delete_grid(grid *g) {
    delete_cells(g);
    free(g);
    g = NULL;
}
