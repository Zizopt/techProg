# KM
### Исполняемый файл KM 
**Для его сбоки нужно подключить библиотеку boost/program_options и указать при вызове cmake опцию -DNOTTEST=ON**
Программа принимает на вход две матрицы, введенных из консоли или считаных из файла, и выдает их произведение или поэлементное произведение
Help программы:
```
Options:
  -h [ --help ]         Help screen
  --action arg          Multiplies matrix if == '*' or multiplies elements of
                        matrix if == '.*'
  --fileA arg           File name A
  --fileB arg           File name B
  --inputA              Input A
  --inputB              Input B
  --nA arg              Input n A
  --nB arg              Input n B
  --mA arg              Input m A
  --mB arg              Input m B
  ```
### mat
Библиотека mat содержит две 
1. `double** multM(double** a, int na, int ma, double** b, int nb, int mb, int &nr, int &mr);`
2. `double** multMElem(double** a, int na, int ma, double** b, int nb, int mb);`

Первая служит для умножения двух матриц, вторая для поэлементного умножения двух матриц.

Документация находится в папке doc

## Результаты тестов:
```
[==========] Running 7 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 7 tests from TestSerialization
[ RUN      ] TestSerialization.MultMElemSizeError
[       OK ] TestSerialization.MultMElemSizeError (0 ms)
[ RUN      ] TestSerialization.MultMElemEqel
[       OK ] TestSerialization.MultMElemEqel (0 ms)
[ RUN      ] TestSerialization.MultMSizeError
[       OK ] TestSerialization.MultMSizeError (0 ms)
[ RUN      ] TestSerialization.MultMEqel
[       OK ] TestSerialization.MultMEqel (0 ms)
[ RUN      ] TestSerialization.TestForTest
D:\a\techProg\techProg\GTmain.cpp(76): error: Expected equality of these values:
  0
  1
[  FAILED  ] TestSerialization.TestForTest (0 ms)
[ RUN      ] TestSerialization.NoMatrixMultMElem
[       OK ] TestSerialization.NoMatrixMultMElem (0 ms)
[ RUN      ] TestSerialization.NoMatrixMultM
[       OK ] TestSerialization.NoMatrixMultM (0 ms)
[----------] 7 tests from TestSerialization (0 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 6 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] TestSerialization.TestForTest

 1 FAILED TEST
```
