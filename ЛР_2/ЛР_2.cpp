#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "rus");
    int* arr = NULL;
    int sizeArr = 0;
    int menu = 0;
    int choice = 0;

    while (1) {
        printf("Выбирите пункт меню, введя номер пункта:\n");
        printf("============Меню==========\n");
        printf("1. Задать размерность массива\n");
        printf("2. Заполнить массив\n");
        printf("3. Вывести массив\n");
        printf("4. Найти три наименьших положительных элементов одномерного массива целых чисел\n");
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
                printf("Введите размер массива (от 4 до 100): ");

                if (scanf_s("%d", &sizeArr) != 1) {
                    printf("Ошибка! Введите целое число.\n");
                    while (getchar() != '\n');
                    continue;
                }

                if (sizeArr < 4 || sizeArr > 100) {
                    printf("Ошибка! Размер должен быть от 4 до 100.\n");
                }
                else {
                    break;
                }
            }

            // Освобождаем предыдущую память, если она была выделена
            if (arr != NULL) {
                free(arr);
            }
            // malloc - выделяет память, sizeof(int) - размер одного числа
            arr = (int*)malloc(sizeArr * sizeof(int));

            // Проверка на то, удалось ли выделить память
            if (arr == NULL) {
                printf("Ошибка выделения памяти!\n");
                return 1; // обрывается программа с ошибкой
            }

            for (int i = 0; i < sizeArr; i++) {
                arr[i] = 0;
            }
            break;
        }

        case 2: {
            if (arr == NULL) {
                printf("Ошибка! Сначала задайте размер массива (пункт 1).\n");
                break;
            }

            while (1) {
                printf("\nВыберите способ заполнения массива:\n");
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
                    for (int i = 0; i < sizeArr; i++) {
                        arr[i] = rand() % 200 - 100; // Числа от -100 до 99
                    }
                    printf("Массив заполнен случайными числами!\n");
                    break;

                case 2:
                    printf("Введите %d элементов массива:\n", sizeArr);
                    for (int i = 0; i < sizeArr; i++) {
                        printf("Элемент %d: ", i + 1);
                        while (scanf_s("%d", &arr[i]) != 1) {
                            printf("Ошибка! Введите целое число: ");
                            while (getchar() != '\n');
                        }
                    }
                    printf("Массив заполнен вручную!\n");
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
            for (int i = 0; i < sizeArr; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        }

        case 4: {
            if (arr == NULL) {
                printf("Ошибка! Сначала задайте размер массива (пункт 1).\n");
                break;
            }

            int count = 0;
            // Ищем три самых маленьких положительных числа
            int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;

            for (int i = 0; i < sizeArr; i++) {
                if (arr[i] > 0 && arr[i]< INT_MAX) {
                    count++;
                }
            }

/*
            // Ищем три самых маленьких положительных числа
            int min1 = 1000, min2 = 1000, min3 = 1000; ///DBL_MAX INT_MAX
            

            for (int i = 0; i < sizeArr; i++) {
                if (arr[i] > 0) {
                    count++;

                    // Обновляем все три значения по порядку
                    if (arr[i] < min1) {
                        min3 = min2;
                        min2 = min1;
                        min1 = arr[i];
                    }
                    else if (arr[i] < min2) {
                        min3 = min2;
                        min2 = arr[i];
                    }
                    else if (arr[i] < min3) {
                        min3 = arr[i];
                    }
                }
            }
*/
            // Показываем результаты поиска
            printf("\nРезультаты поиска:\n");
            if (count == 0) {
                printf("В массиве нет положительных элементов\n");
            }
            else if (count == 1) {
                printf("Найден один положительный элемент: %d\n", min1);
            }
            else if (count == 2) {
                printf("Найдено два положительных элемента: %d и %d\n", min1, min2);
            }
            else {
                printf("Три наименьших положительных элемента: %d, %d, %d\n", min1, min2, min3);
            }
            break;
        }

        case 5:
            printf("Завершение программы\n");
            if (arr != NULL) {
                free(arr);
            }
            return 0;

        default:
            printf("Ошибка!\n");
            break;
        }
    }

    return 0;
}
