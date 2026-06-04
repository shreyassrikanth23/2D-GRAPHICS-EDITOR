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

void drawLine(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        for (int j = y1; j <= y2; j++)
            canvas[j][x1] = '*';
    } else if (y1 == y2) {
        for (int i = x1; i <= x2; i++)
            canvas[y1][i] = '*';
    }
}

void drawTriangle(int x, int y, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j <= i; j++)
            if (i == size - 1 || j == 0 || j == i)
                canvas[x + i][y + j] = '*';
}

void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (y >= x) {
        canvas[yc + y][xc + x] = '*';
        canvas[yc + y][xc - x] = '*';
        canvas[yc - y][xc + x] = '*';
        canvas[yc - y][xc - x] = '*';
        canvas[yc + x][xc + y] = '*';
        canvas[yc + x][xc - y] = '*';
        canvas[yc - x][xc + y] = '*';
        canvas[yc - x][xc - y] = '*';
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

void clearCanvas() {
    initCanvas();
}

int main() {
    int choice;
    initCanvas();

    while (1) {
        printf("\n--- 2D GRAPHICS EDITOR ---\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Clear Canvas\n");
        printf("6. Display Canvas\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int x, y, w, h;
                printf("Enter x y width height: ");
                scanf("%d %d %d %d", &x, &y, &w, &h);
                drawRectangle(x, y, w, h);
                break;
            }
            case 2: {
                int x1, y1, x2, y2;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                drawLine(x1, y1, x2, y2);
                break;
            }
            case 3: {
                int x, y, size;
                printf("Enter x y size: ");
                scanf("%d %d %d", &x, &y, &size);
                drawTriangle(x, y, size);
                break;
            }
            case 4: {
                int xc, yc, r;
                printf("Enter center(x,y) and radius: ");
                scanf("%d %d %d", &xc, &yc, &r);
                drawCircle(xc, yc, r);
                break;
            }
            case 5:
                clearCanvas();
                printf("Canvas cleared!\n");
                break;
            case 6:
                displayCanvas();
                break;
            case 7:
                printf("Exiting editor...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
