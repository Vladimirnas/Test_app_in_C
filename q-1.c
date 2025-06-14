#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 80   // Ширина сетки
#define HEIGHT 25  // Высота сетки

void create_grid(int grid[HEIGHT][WIDTH]) {
    // Инициализация сетки случайными живыми клетками
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2;  // 0 или 1
        }
    }
}

void load_grid_from_file(int grid[HEIGHT][WIDTH], const char *filename) {
    // Загружает сетку из файла
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Ошибка открытия файла");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            char ch;
            fscanf(file, " %c", &ch);          // Считываем символ
            grid[i][j] = (ch == '1') ? 1 : 0;  // Преобразуем символы в 1 и 0
        }
    }

    fclose(file);
}

void print_grid(int grid[HEIGHT][WIDTH]) {
    // Очистка экрана
    printf("\033[H\033[J");  // ANSI escape код для очистки экрана
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", grid[i][j] ? 'O' : ' ');  // 'O' для живой клетки, ' ' для мертвой
        }
        printf("\n");
    }
}

int count_neighbors(int grid[HEIGHT][WIDTH], int x, int y) {
    // Считает количество живых соседей для клетки (x, y) с учетом замкнутого поля
    int neighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;  // Пропускаем саму клетку

            // Используем модуль для замыкания
            int nx = (x + i + HEIGHT) % HEIGHT;  // Замкнутое по вертикали
            int ny = (y + j + WIDTH) % WIDTH;    // Замкнутое по горизонтали

            neighbors += grid[nx][ny];
        }
    }
    return neighbors;
}

void update_grid(int grid[HEIGHT][WIDTH]) {
    // Обновляет сетку по правилам игры
    int new_grid[HEIGHT][WIDTH] = {0};
    for (int x = 0; x < HEIGHT; x++) {
        for (int y = 0; y < WIDTH; y++) {
            int neighbors = count_neighbors(grid, x, y);
            if (grid[x][y] == 1) {
                new_grid[x][y] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                new_grid[x][y] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
    // Копируем новое состояние в старую сетку
    for (int x = 0; x < HEIGHT; x++) {
        for (int y = 0; y < WIDTH; y++) {
            grid[x][y] = new_grid[x][y];
        }
    }
}

int main() {
    srand(time(NULL));  // Инициализация генератора случайных чисел
    int grid[HEIGHT][WIDTH];

    char filename[100];
    printf("Введите имя файла для загрузки начальной конфигурации: ");
    scanf("%s", filename);
    load_grid_from_file(grid, filename);

    float speed;
    printf("Введите скорость игры (в секундах, например, 0.5): ");
    scanf("%f", &speed);

    while (1) {
        print_grid(grid);
        update_grid(grid);
        usleep(speed * 1000000);  // Задержка в микросекундах
    }

    return 0;
}
