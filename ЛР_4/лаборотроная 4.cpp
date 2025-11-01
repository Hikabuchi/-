#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// выделение  памяти
int** memmoryMatrix(int rows, int cols) {//int** рлтому что функция должна вернуть указатель на указатель на int
    int** arr = (int**)malloc(rows * sizeof(int*));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Ошибка выделения памяти!\n");
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return NULL;
        }
        for (int j = 0; j < cols; j++) 
            arr[i][j] = 0;
    }

    return arr;
}

//  освобождения памяти
void freeMatrix(int** arr, int rows) {
    if (arr != NULL) {
        for (int i = 0; i < rows; i++) {
            free(arr[i]);
        }
        free(arr);
    }
}

// функция для ввода размерности матрицы
void inputDimensions(int* rows, int* cols) {
    while (1) {
        printf("Введите количество строк в матрице: ");
        if (scanf_s("%d", rows) != 1) {
            printf("Ошибка! Введите целое число.\n");
            while (getchar() != '\n');
            continue;
        }
        if (*rows < 2 || *rows > 100) {
            printf("Ошибка! Строк должно быть от 2 до 100.\n");
        }
        else {
            break;
        }
    }

    while (1) {
        printf("Введите количество столбцов в матрице: ");
        if (scanf_s("%d", cols) != 1) {
            printf("Ошибка! Введите целое число.\n");
            while (getchar() != '\n');
            continue;
        }
        if (*cols < 2 || *cols > 100) {
            printf("Ошибка! Столбцов должно быть от 2 до 100.\n");
        }
        else {
            break;
        }
    }
}

// функция для заполнения рандомными значениями
void fillMatrixRandom(int** arr, int rows, int cols) {
    printf("Заполнение массива ...\n");
    srand((unsigned int)time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 200 - 100;
        }
    }
    printf("Матрица заполнена случайными числами!\n");
}

// Функция для заполнения матрицы вручную
void fillMatrixManual(int** arr, int rows, int cols) {
    printf("Введите %dx%d элементов массива:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        printf(" Строка %d: ", i + 1);
        for (int j = 0; j < cols; j++) {
            printf(" Элемент [%d][%d]: ", i + 1, j + 1);
            while (scanf_s("%d", &arr[i][j]) != 1) {
                printf("Ошибка! Введите целое число: ");
                while (getchar() != '\n');
            }
        }
    }
    printf("Матрица заполнена вручную!\n");
}

// Функция для выбора способа заполнения матрицы
void fillMatrix(int** arr, int rows, int cols) {
    int choice = 0;

    while (1) {
        printf("\nВыберите способ заполнения матрицы:\n");
        printf("1. Случайными числами\n");
        printf("2. Вручную с клавиатуры\n");
        printf("Ваш выбор: ");
        if (scanf_s("%d", &choice) != 1) {
            printf("Ошибка! Введите целое число.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
        case 1:
            // вызов функции заполнения рандомными значениями
            fillMatrixRandom(arr, rows, cols);
            return;
        case 2:
            // вызов функции заполнения вручную
            fillMatrixManual(arr, rows, cols);
            return;
        default:
            printf("Ошибка! Введите 1 или 2.\n");
            continue;
        }
    }
}

//вывод матрицы
void printMatrix(int** arr, int rows, int cols) {
    printf("\nСодержимое массива:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Функция для сортировки строк матрицы по первому элементу
void sortMatrix(int** arr, int rows, int cols) {
    for (int i = 0; i < rows - 1; i++) {
        for (int k = 0; k < rows - i - 1; k++) {
            if (arr[k][0] > arr[k + 1][0]) {
                int* temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
}

// Функция меню
void displayMenu() {
    printf("============Упорядочить строки матрицы в порядке возрастания их первых элементов.==========\n");
    printf("Выбирите пункт меню, введя номер пункта:\n");
    printf("============Меню==========\n");
    printf("1. Задать размерность матрицы\n");
    printf("2. Заполнить матрицу\n");
    printf("3. Вывести заполненую матрицу\n");
    printf("4. Произвести сортировку\n");
    printf("5. Выйти\n");
}

int main() {
    setlocale(LC_ALL, "rus");
    int** arr = NULL;
    int rows = 0, cols = 0;
    int menu = 0;

    while (1) {
        displayMenu();
        if (scanf_s("%d", &menu) != 1) {
            printf("Ошибка! Введите целое число.\n");
            while (getchar() != '\n');
            continue;
        }
        if (menu <= 0 || menu > 5) {
            printf("Ошибка! Номер пункта должен быть от 1 до 5.\n");
            continue;
        }
        switch (menu) {
        case 1: {
            inputDimensions(&rows, &cols);

            freeMatrix(arr, rows);
            arr = memmoryMatrix(rows, cols);

            if (arr != NULL) {
                printf("Память для матрицы размерностью %dx%d была выделена\n", rows, cols);
            }
            break;
        }
        case 2: {
            if (arr == NULL) {
                printf("Ошибка! Сначала задайте размерность матрицы (пункт 1).\n");
                break;
            }
            fillMatrix(arr, rows, cols);
            break;
        }
        case 3: {
            if (arr == NULL) {
                printf("Ошибка! Сначала задайте размер массива (пункт 1).\n");
                break;
            }
            printMatrix(arr, rows, cols);
            break;
        }
        case 4: {
            if (arr == NULL) {
                printf("Ошибка! Сначала задайте размерность матрицы (пункт 1).\n");
                break;
            }
            sortMatrix(arr, rows, cols);
            printf("Матрица отсортирована!\n");
            printMatrix(arr, rows, cols);
            break;
        }
        case 5: {
            freeMatrix(arr, rows);
            printf("Программа завершена\n");
            return 0;
        }
        default:
            printf("Ошибка меню!\n");
            break;
        }
    }
    return 0;
}