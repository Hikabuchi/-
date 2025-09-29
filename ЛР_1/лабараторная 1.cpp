
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    double a, b, u;
    printf("Идентификация треугольника по двум сторонам и углу между ними\n");

    while (true) {
        printf("Введите длину первой стороны:");
        if (scanf_s("%lf", &a) != 1) {
            printf("Ошибка ввода данных: введите числовое значение\n");
            // Переходит к следующей итерации цикла while, чтобы снова запросить ввод.
            while ((a=getchar()) && (a != '\n'));
            continue;
        }
        else{
            if (a <= 0) {
                printf("Ошибка ввода данных: сторона должна быть положительным числом\n");
                continue;
            }
            break;
        }
    }
  
    while (true) {
        printf("Введите длину второй стороны:");
        if (scanf_s("%lf", &b) != 1) {
            printf("Ошибка ввода данных: введите числовое значение\n");
            while ((b=getchar()) && (b != '\n'));
            continue;
        }
        else {
            if (b <= 0) {
                printf("Ошибка ввода данных: сторона должна быть положительным числом\n");
                continue;
            }
            break;
        }
    }

    while (true) {
        printf("Введите угол между сторонами:");
        if (scanf_s("%lf", &u) != 1) {
            printf("Ошибка ввода данных: введите числовое значение\n");
            while ((u=getchar()) && (u != '\n'));
            continue;
        }
        else {
            if (u <= 0 || u >= 180) {
                printf("Ошибка ввода данных: угол меду сторонами должен быть от 0 дл 180\n");
             continue;
                    }
             break;
        }
        
    }
 
    double u_radians = u * 3.1415926535 / 180.0;//Перевожу градусы в радианы по формуле
    double c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(u_radians));

    printf("\nСтороны треугольника: %f, %f, %f\n", a, b, c);

    if (c <= 0) {
        printf("Треугольник с такими сторонами не существует\n");
    }
    
    const double EPSILON = 1e-2;

    if ((fabs(a - b) < EPSILON) && (fabs(b - c) < EPSILON)) {
        printf("Треуголльник: равносторонний");
    }
    else if((fabs(a - b) < EPSILON || fabs(b - c) < EPSILON || fabs(c - a) < EPSILON) && (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2)))
    {
        printf("Треуголльник: равнобедренный и прямоугольный");
    }
    else if (fabs(a - b) < EPSILON || fabs(b - c) < EPSILON || fabs(c - a) < EPSILON) {
        printf("Треуголльник: равнобедренный");
    }
    else if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2)) {
        printf("Треуголльник: прямоугольный");
    }
    else {
        printf("Треуголльник: разносторонний");
    }
      return 0;
}
