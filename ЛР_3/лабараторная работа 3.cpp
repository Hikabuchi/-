
#include <iostream>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	int** arr = NULL;
	int rows = 0, cols = 0;
	int menu = 0;
	int choice = 0;

	//Ввод
	while (1) {
        printf("============Упорядочить строки матрицы в порядке возрастания их первых элементов.==========\n");
		printf("Выбирите пункт меню, введя номер пункта:\n");
		printf("============Меню==========\n");
		printf("1. Задать размерность матрицы\n");
		printf("2. Заполнить матрицу\n");
		printf("3. Вывести заполненую матрицу\n");
		printf("4. Произвести сортировку\n");
		printf("5. Выйти\n");

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
            while (1) {
                printf("Введите количество строк в матрице: ");

                if (scanf_s("%d", &rows) != 1) {
                    printf("Ошибка! Введите целое число.\n");
                    while (getchar() != '\n');
                    continue;
                }

                if (rows < 2 || rows > 100) {
                    printf("Ошибка! Строк должно быть от 2 до 100.\n");
                }
                else {
                    break;
                }
            }
            while (1) {
                printf("Введите количество столбцов в матрице: ");

                if (scanf_s("%d", &cols) != 1) {
                    printf("Ошибка! Введите целое число.\n");
                    while (getchar() != '\n');
                    continue;
                }

                if (cols < 2 || cols > 100) {
                    printf("Ошибка! Столбцов должно быть от 2 до 100.\n");
                }
                else {
                    break;
                }
            }

            // Освобождаем предыдущую память, если она была выделена
            if (arr != NULL) {
                for (int i = 0; i < rows; i++)
                {
                    free(arr[i]);
                }
                free(arr);
            }
            // malloc - выделяет память, sizeof(int) - размер одного числа
            arr = (int**)malloc(rows * sizeof(int));
            // Проверка на то, удалось ли выделить память
            if (arr == NULL) {
                printf("Ошибка выделения памяти!\n");
                return 1; // обрывается программа с ошибкой
            }
            for (int i = 0; i < rows; i++)
            {
                arr[i]= (int*)malloc(cols * sizeof(int));
                if (arr == NULL) {
                    printf("Ошибка выделения памяти!\n");
                    for (int j = 0; j < i; j++)
                    {
                        free(arr[i]);
                    }free(arr);
                    return 1; // обрывается программа с ошибкой
                }
                for (int j = 0; j < cols; j++)
                {
                    arr[i][j] = 0;
                }
            }
            printf("Память для матрицы размерностью %dx%d была выделена", rows, cols);
            break;
        }
        case 2: {
            if (arr == NULL) {
                printf("Ошибка! Сначала задайте размерность матрицы (пункт 1).\n");
                break;
            }

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
                    printf("Заполнение массива ...\n");
                    srand((unsigned int)time(NULL));
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++)
                        {
                            arr[i][j] = rand() % 200 - 100; // Числа от -100 до 99
                        }
                        
                    }
                    printf("Матрица заполнена случайными числами!\n");
                    break;

                case 2:
                    printf("Введите %dx%d элементов массива:\n", rows, cols);
                    for (int i = 0; i < rows; i++) {
                        printf(" Строка %d: ", i + 1);
                        for (int j = 0; j < cols; j++)
                        {
                            printf(" Элемент [%d][%d]: ", i + 1, j + 1);
                            while (scanf_s("%d", &arr[i][j]) != 1) {
                                printf("Ошибка! Введите целое число: ");
                                while (getchar() != '\n');
                            }
                        }
                    }
                    printf("Матрица заполнена вручную!\n");
                    break;

                default:
                    printf("Ошибка! Введите 1 или 2.\n");
                    continue;
                }
                break;
            }
            break;
        }
        case 3: {
            if (arr == NULL) {
                printf("Ошибка! Сначала задайте размер массива (пункт 1).\n");
                break;
            }

            printf("\nСодержимое массива:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++)
                {
                    printf("%d \t", arr[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            break;
        }
        case 4: {
            if (arr == NULL) {
                printf("Ошибка! Сначала задайте размерность матрицы (пункт 1).\n");
                break;
            }

            
            for (int i = 0; i < rows - 1; i++)//проходы
            {
                for (int k = 0; k < rows - i - 1; k++) {// сравнения и rows - i - 1 уменьшение обасти обхода
                    if (arr[k][0] > arr[k+1][0]) {
                        int* temp = arr[k];
                        arr[k] = arr[k + 1];
                        arr[k + 1] = temp;
                    }
               }
            }

            printf("\nСодержимое отсортированной матрицы:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++)
                {
                    printf("%d \t", arr[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            break;
        }
        case 5: {
            if (arr != NULL) {
                for (int i = 0; i < rows; i++)
                {
                    free(arr[i]);
                }
               free(arr);
            }
            printf("Программа завершина\n");
            return 0;
        }
            
        default:
            printf("Ошибка меню!\n");
            break;
        }
    }

    return 0;
}
