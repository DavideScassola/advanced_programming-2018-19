#include<iostream>
#include<array>

template<size_t N, typename T>
void transpose(std::array<T,N>& matrix, int n_row, int n_col)
{
	std::array<T,N> temp;
	
	//strided access in reading, contiguous in writing
	for(int j{0}; j<n_col; j++)
		for(int i{0}; i<n_row; i++)
			temp[j*n_row + i] = matrix[i*n_col + j];
	
	matrix = temp;
}

template<size_t N>
std::array<double,N> exampleMatrix(int n_row, int n_col)
{
		int value{10};
		std::array<double,N> matrix;
		for(int i{0}; i<n_row; i++)
			for(int j{0}; j<n_col; j++)
			{
				int i_j = i*n_col + j;
				matrix[i_j] = value++;
			}

		return matrix;
}

template<size_t N, typename T>
void printMatrix(std::array<T,N>& matrix, int n_row, int n_col)
{
		for(int i{0}; i<n_row; i++)
		{
			for(int j{0}; j<n_col; j++)
			{
				int i_j = i*n_col + j;
				std::cout << matrix[i_j] << " ";
			}
			
			std::cout << "\n";
		}

		std::cout << "\n\n";
}

main()
{
	const int n_row = 8;
	const int n_col = 6;
	const int size = n_row*n_col;

	std::array<double,size> matrix = exampleMatrix<size>(n_row,n_col);

	printMatrix<size,double>(matrix, n_row, n_col);
	transpose<size,double>(matrix, n_row, n_col);
	printMatrix<size,double>(matrix, n_col, n_row);
}
