
# Лабораторная работа №II

## Разработка библиотеки для операций над матрицами с помощью инструментального программного обеспечения в ОС Линукс.

# Оглавление

- [Описание проекта](#описание-проекта)
- [Цель работы](#цель-работы)
- [Задание](#задание)
- [Структура проекта](#структура-проекта)
- [Используемые функции](#функции)
- [Основные команды](#основные-команды)
- [Вывод](#вывод)


   
## Описание проекта

Данный проект - библиотека для произведения операций над матрицами выполненная на языке С.


### Цель работы:

1. Ознакомление с особенностями реализации основных операций над матрицами (создание,
ввод / вывод, сложение, умножение, транспонирование, нахождение детерминанта).
2. Закрепление навыков по использованию механизмов работы с указателями и
динамическим выделением памяти в языке C для матриц.
3. Настройка автоматизированной сборки Makefile.
4. Настройка системы контроля версий с использованием git.
4.1 Создание репозитория для проекта.
4.2 Базовые операции работы с версиями кода.
4.3 Оформление README-файла с описанием функциональности библиотеки для
github.com.
5. Освоение инструментов отладки кода с помощью gdb.
5.1 Работа с точками останова в критических частях кода.
5.2 Поэтапная трассировка выполнения программы.
5.3. Анализ значений переменных в процессе выполнения.
6. Анализ корректности кода программы с помощью инструментов cppcheck, clang-analyzer,
valgrind.
7. Подготовка автотестов для проверки корректности работы библиотеки с использованием
фреймворка CUnit.
8. Выполнение разметки кода с использованием Doxygen, генерирование документации.
9. Выполнение индивидуального задания, связанного с вычислением выражений с
динамическими матрицами, используя разработанную библиотеку. Номер задания
определяется номером студента в журнале. Если номер превышает максимальное количество
заданий, вариант вычисляется по формуле: номер по журналу % максимальный номер
задания (где % — остаток от деления).
10. Отразить в отчёте:
а) описание структуры разработанной библиотеки;
б) тексты библиотеки и тестов с комментариями;
в) подготовленные тестовые данные и результаты;
г) иные материалы, относящиеся к ходу выполнения работы;
д) выводы о корректности и эффективности реализации.


### Задание:

1.  Создать библиотеку, содержащую функции для работы с динамическими матрицами. В
библиотеке реализовать:
1.1. Создание и освобождение памяти под матрицу.
1.2. Ввод матрицы (предусмотреть загрузку файлов из текстового файла).
1.3. Вывод матрицы.
1.4. Копирование матриц.
1.5. Операция сложения матриц.
1.6. Операция умножения матриц.
1.7. Транспонирование матрицы.
1.8. Нахождение детерминанта (рекурсивный метод).
2.  Выполнить отладку, автоматические: тестирование, анализ корректности, форматирование
кода, сборку и документирование проекта. Подготовить код для работы с распределенной
системой управления версиями.
3.  Выполнить индивидуальное задание.


### Структура проекта
```
/matrix_project
│── src/
│ │── matrix/
│ │ │── matrix.c     # Основная реализация операций с матрицами
│ │ │── matrix.h     # Заголовочный файл для matrix
│ │── output/
│ │ │── output.c     # Функции вывода матриц в консоль и файлы
│ │ │── output.h     # Заголовочный файл для output
│ │── errors/
│ │ │── errors.c     # Функции для вывода ошибок
│ │ │── errors.h     # Заголовочный файл для errors
│ │── main.c         # main
│── include/
│ │── config.h       # Файл для настроек
│── tests/
│ │── tests_matrix.c # Набор тестов для matrix
│ │── tests_output.c # Набор тестов для output
│ │── tests_main.c   # Общие тесты
│ │── test_runner.c  # Запуск тестов с использованием CUnit
│── docs/            # Сгенерированная документация Doxygen
│── build/           # Каталог для временных файлов
│── input_matrices/  # Каталог хранящий файлы матриц
│── Makefile         # Файл для сборки проекта
│── README.md        # Описание проекта
│
│── .gitignore       # gitignore
│── .clang-format    # Форматирования кода
│── .github/         
```

 
## Функции

### Функции для работы с матрицами:
Функция | Описание
--- | ---
`create_matrix()` | Создание матрицы
`free_matrix()` | Освобождение памяти
`load_matrix_from_file()` | Загрузка матрицы из файла
`print_matrix()` | Вывод матрицы в консоль
`save_matrix_to_file()` | Сохранение матрицы в файл
`add_matrices()` | Сложение двух матриц
`subtract_matrices()` | Вычитание двух матриц
`multiply_matrices()` | Умножение матриц
`transpose_matrix()` | Транспонирование матрицы
`determinant()` | Детерминант квадратной матрицы

### Функции для вывода
Функция | Описание
--- | ---
`output_print_matrix`           | Вывод матрицы в консоль
`output_save_matrix_to_file`    | Сохранение матрицы в файл
`output_load_matrix_from_file` | Загрузка матрицы из файла


## Основные команды

**Собрать приложение:**
```sh
make all
```


**Запустить тесты:**
```sh
make test
```


**Запустить приложение:**
```sh
make run
```


**Очистить проект:**
```sh
make clean
```


**Форматировать код:**
```sh
make format
```


**Посмотреть все команды:**
```sh
make help
```

## Вывод
В результате работы созданы библиотеки и с их помощью проведены действия над множествами.

