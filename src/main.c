/**
 * @file main.c
 * @brief 
 *
 * @details
 * Программа вычисляет выражение выражение A × B + C - D^T.
 *
 * Алгоритм программы:
 * 1.Загрузка матриц A, B, C, D из файлов
 * 2.Умножение A на B
 * 3.Сложение с матрицей C
 * 4.Транспонирование матрицы D
 * 5.Вычитание матрицы D^T
 * 6.Сохранение результата
 *
 * @return 1 при успешном выполнении, 0 при ошибке
 *
 * @note Для работы требуются файлы в папке data/
 *
 * @see matrix.h output.h
 */

#include "matrix/matrix.h"
#include "output/output.h"

#include <stdio.h>
#include <stdlib.h>

int main () {
    int res = 1;   //Флаг для проверки выполнения операции

    Matrix A = load_matrix_from_file ("input_matrices/matrix_a.txt");
    Matrix B = load_matrix_from_file ("input_matrices/matrix_b.txt");
    Matrix C = load_matrix_from_file ("input_matrices/matrix_c.txt");
    Matrix D = load_matrix_from_file ("input_matrices/matrix_d.txt");

    if (!A.data || !B.data || !C.data || !D.data) {
        res = 0;
        fprintf (stderr, "Ошибка загрузки матриц.\n");
    }

    Matrix AB = {0};
    if (res) {
        AB = create_matrix (A.rows, B.cols);
        if (!AB.data) {
            res = 0;
            fprintf (stderr, "Ошибка создания матрицы AB.\n");
        }
    }

    //1 действие
    if (res) {
        if (multiply_matrices (&A, &B, &AB) != 0) {
            res = 0;
            fprintf (stderr, "Ошибка умножения матриц.\n");
        }
    }

    // 2 действие
    Matrix AB_plus_C = {0};
    if (res) {
        AB_plus_C = create_matrix (AB.rows, AB.cols);
        if (!AB_plus_C.data) {
            res = 0;
            fprintf (stderr, "Ошибка создания матрицы AB_plus_C.\n");
        }
    }

    if (res) {
        if (add_matrices (&AB, &C, &AB_plus_C) != 0) {
            res = 0;
            fprintf (stderr, "Ошибка сложения матриц.\n");
        }
    }
    
    //3 действие
    Matrix D_transpose = {0};
    if (res) {
        D_transpose = transpose_matrix (&D);
        if (!D_transpose.data) {
            res = 0;
            fprintf (stderr, "Ошибка транспонирования D.\n");
        }
    }

    // 4 действие
    Matrix result = {0};
    if (res) {
        result = create_matrix (AB_plus_C.rows, AB_plus_C.cols);
        if (!result.data) {
            res = 0;
            fprintf (stderr, "Ошибка создания финальной матрицы.\n");
        }
    }

    if (res) {
        if (subtract_matrices (&AB_plus_C, &D_transpose, &result) != 0) {
            res = 0;
            fprintf (stderr, "Ошибка вычитания матриц.\n");
        }
    }

    //Вывод
    if (res) {
        printf ("Результат выражения A × B + C - D^T:\n");
        print_matrix (&result);

        if (save_matrix_to_file (&result, "input_matrices/result.txt") != 0) {
            res = 0;
            fprintf (stderr, "Ошибка сохранения результата.\n");
        } else {
            printf ("Результат сохранен в input_matrices/result.txt\n");
        }
    }

    //Освобождаем память
    free_matrix (&A);
    free_matrix (&B);
    free_matrix (&C);
    free_matrix (&D);
    free_matrix (&D_transpose);
    free_matrix (&AB);
    free_matrix (&AB_plus_C);
    free_matrix (&result);

    return res ? 0 : 1;
}
