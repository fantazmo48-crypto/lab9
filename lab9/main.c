#include <stdio.h>
#include <locale.h>
#include <math.h>
#define ROW 9
#define COL 9

int main()
{
	setlocale(LC_ALL, ".UTF-8");
	Work1Pifagor();
	Work1Variant2();
	Work2Pro();
	HomeWork();
	return 0;
}

int Work1Pifagor()
{
    int row, col;
	puts("Задание 1");
    for (row = 1; row <= ROW; row++) {
        // Условие col <= row обеспечивает вывод треугольника
        for (col = 1; col <= row; col++) {
            printf_s("%5d", col * row);
        }
        printf_s("\n");
    }
    system("pause");
	puts("\n\n\n");
    return 0;
}

int Work1Variant2()
{
    int row, col;
    puts("Задание 1.2");
    // 4 строки
    for (row = 1; row <= 4; row++) {
        // Числа от 1 до 10
        for (col = 1; col <= 10; col++) {
            printf_s("%5d", col);
        }
        printf_s("\n");
    }
    system("pause");
    puts("\n\n\n");
    return 0;
}

int Work2Pro()
{
    char choice;
	puts("Задание 2\n");
    // Цикл do-while для повтора программы
    do {
        char str[100];
        printf_s("Введите число: ");
        scanf_s("%s", str, 100);

        int len = strlen(str); // длина числа

        // 1) Количество цифр 3
        int count3 = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == '3') {
                count3++;
            }
        }
        printf_s("1) Количество цифр 3: %d\n", count3);

        // 2) Повторений последней цифры
        char lastChar = str[len - 1];
        int countLast = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == lastChar) {
                countLast++;
            }
        }
        printf_s("2) Повторений последней цифры (%c): %d\n", lastChar, countLast);

        // 3) Количество четных цифр
        int countEven = 0;
        for (int i = 0; i < len; i++) {
            int digit = str[i] - '0'; // переводим символ в цифру
            if (digit % 2 == 0) {
                countEven++;
            }
        }
        printf_s("3) Количество четных цифр: %d\n", countEven);

        // 4) Количество цифр больше 5
        int countGt5 = 0;
        for (int i = 0; i < len; i++) {
            int digit = str[i] - '0';
            if (digit > 5) {
                countGt5++;
            }
        }
        printf_s("4) Количество цифр больше 5: %d\n", countGt5);

        // 5) Сумма нечетных цифр
        int sumOddDigits = 0;
        for (int i = 0; i < len; i++) {
            int digit = str[i] - '0';
            if (digit % 2 != 0) {
                sumOddDigits += digit;
            }
        }
        printf_s("5) Сумма нечетных цифр: %d\n", sumOddDigits);

        // 6) Сумма цифр >= 7
        int sumGe7 = 0;
        for (int i = 0; i < len; i++) {
            int digit = str[i] - '0';
            if (digit >= 7) {
                sumGe7 += digit;
            }
        }
        printf_s("6) Сумма цифр >= 7: %d\n", sumGe7);

        // 7) Произведение всех цифр (исключая 0)
        long long prod = 1;
        for (int i = 0; i < len; i++) {
            int digit = str[i] - '0';
            if (digit != 0) {
                prod *= digit;
            }
        }
        printf_s("7) Произведение цифр (без 0): %lld\n", prod);

        // 8) Произведение предпоследней и второй цифры
        if (len >= 2) {
            int second = str[1] - '0';
            int penult = str[len - 2] - '0';
            printf_s("8) Произведение 2-й (%d) и предпоследней (%d) цифр: %d\n", second, penult, second * penult);
        }
        else {
            printf_s("8) Мало цифр в числе\n");
        }

        // 9) Сумма четных цифр, исключая последнюю
        int sumEvenNotLast = 0;
        for (int i = 0; i < len - 1; i++) { // len - 1 пропуск последней цифры
            int digit = str[i] - '0';
            if (digit % 2 == 0) {
                sumEvenNotLast += digit;
            }
        }
        printf_s("9) Сумма четных цифр (без последней): %d\n", sumEvenNotLast);

        // 10) Рядом расположенные одинаковые цифры
        printf_s("10) Соседние одинаковые цифры: ");
        int found = 0;
        for (int i = 0; i < len - 1; i++) {
            if (str[i] == str[i + 1]) {
                printf_s("%c ", str[i]);
                found = 1;
            }
        }
        if (!found) {
            printf_s("нет");
        }
        printf_s("\n");

        // 11) Равна ли сумма первой и второй половины цифр
        int half = len / 2;
        int sumHalf1 = 0;
        int sumHalf2 = 0;
        for (int i = 0; i < half; i++) {
            sumHalf1 += (str[i] - '0');
        }
        for (int i = len - half; i < len; i++) {
            sumHalf2 += (str[i] - '0');
        }
        if (sumHalf1 == sumHalf2) {
            printf_s("11) Суммы половин РАВНЫ (%d = %d)\n", sumHalf1, sumHalf2);
        }
        else {
            printf_s("11) Суммы половин НЕ равны (%d != %d)\n", sumHalf1, sumHalf2);
        }

        // 12) Произведение сумм цифр нечетных и четных разрядов (справа налево)
        int sumOddPos = 0;
        int sumEvenPos = 0;
        for (int i = 0; i < len; i++) {
            int pos = len - i; // позиция справа налево (1, 2, 3...)
            int digit = str[i] - '0';
            if (pos % 2 != 0) {
                sumOddPos += digit;
            }
            else {
                sumEvenPos += digit;
            }
        }
        printf_s("12) Произведение сумм нечетных (%d) и четных (%d) разрядов: %d\n",
            sumOddPos, sumEvenPos, sumOddPos * sumEvenPos);

        // Вопрос на повторение программы
        printf_s("\nПродолжить? (y/n): ");
        scanf_s(" %c", &choice, 1);
        printf_s("\n\n\n");

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

int HomeWork()
{
    char sym;
    int s1, s2, s3;
    puts("Домашнее задание");
    printf_s("Введите символ для рисования: ");
    scanf_s(" %c", &sym);
    printf_s("Введите размер стороны 1 (левый верхний квадрат): ");
    scanf_s("%d", &s1);
    printf_s("Введите размер стороны 2 (пересечение): ");
    scanf_s("%d", &s2);
    printf_s("Введите размер стороны 3 (правый нижний квадрат): ");
    scanf_s("%d", &s3);

    // Примерная логика отрисовки:
    // Размеры холста должны быть достаточными для размещения фигур
    int height = s1 + s3;
    int width = s1 + s3;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Условие для первого квадрата (0,0 до s1,s1)
            int in_sq1 = (i < s1 && j < s1);

            // Условие для второго квадрата (смещенного)
            // Координаты смещения зависят от того, как именно должны пересекаться квадраты
            int in_sq2 = (i >= s1 - s2 && i < s1 - s2 + s3 && j >= s1 - s2 && j < s1 - s2 + s3);

            if (in_sq1 || in_sq2) {
                printf_s("%c", sym);
            }
            else {
                printf_s(" ");
            }
        }
        printf_s("\n");
    }

    return 0;
}