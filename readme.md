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