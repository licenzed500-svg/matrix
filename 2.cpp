// вариант 6 задача 5

#include <iostream>
#include <time.h>
#include <vector>



void out_matrix(std::vector<std::vector<short>> &matrix)
{
    for(auto i = 0; i<matrix.size(); i++)
    {
        for(auto j = 0; j<matrix[i].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}



void make_matrix(std::vector<std::vector<short>> &matrix)
{
    const short min = -10;
    const short max = 10;
    for(auto i = 0; i<matrix.size(); i++)
    {
        for(auto j = 0; j<matrix[i].size(); j++)
        {
            matrix[i][j] = min+rand()%(max-min);
        }
    }
}



int found_min_replace(std::vector<std::vector<short>> &matrix)
{
    int sum_dia = 0;
    for(auto i = 0; i<matrix.size(); i++)
    {
        for(auto j = 0; j<matrix[i].size(); j++)
        {
            short min_element = matrix[i][0];
            {
                if(matrix[i][j] < min_element)
                {
                    matrix[i][i] = min_element;
                }
            }
        }
    }
    return sum_dia;
}



int main() {
    srand(time(NULL));
    const short matrix_cols_rows = 10;
    
    
    std::vector<std::vector<short>> matrix(matrix_cols_rows , std::vector<short> (matrix_cols_rows));
    
    make_matrix(matrix);
    
    out_matrix(matrix);
    int sum_dia = found_min_replace(matrix);
    
    std::cout << "\n\n sum is:" << sum_dia << "\n\n";
}
