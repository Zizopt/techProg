#pragma once
/**
	\file
	Заголовочный файл для функции перемножения матриц.
*/
/**
	\brief Функция, считающая произведение матриц.
	\details Функция возвращает матрицу C, равную произведению матриц A на B.
	\param[in] a первая матрица A
	\param[in] na количество строк матрицы А
	\param[in] ma количество столбцов матрицы А
	\param[in] b вторая матрица B
	\param[in] nb количество строк матрицы B
	\param[in] mb количество столбцов матрицы B
	\param[out] nr количество строк матрицы B
	\param[out] mr количество столбцов матрицы B
	\return матрица C = A * B
	
*/
double** multM(double** a, int na, int ma, double** b, int nb, int mb, int &nr, int &mr);
