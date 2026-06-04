#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initCanvas() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            canvas[i][j] = ' ';
}

void displayCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%c", canvas[i][j]);
        printf("\n");
    }
}

void drawRectangle(int x, int y, int w, int h) {
    for (int i = x; i < x + h; i++)
        for (int j = y; j < y + w; j++)
            if (i == x || i == x + h - 1 || j == y || j == y + w - 1)
                canvas[i][j] = '*';
}

int main() {
    initCanvas();
    drawRectangle(2, 5, 10, 6);
    displayCanvas();
    return 0;
}
