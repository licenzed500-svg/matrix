//вариант 6 задача 6

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

void out_max(std::vector<short> &max_elements)
{
    for(auto i : max_elements)
    {
        std::cout << "\n" << i << "\n";
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



void found_max_make_arr(std::vector<std::vector<short>> &matrix, std::vector<short> &max_elements)
{
    for(auto i = 0; i<matrix.size(); i++)
    {
        short max = matrix[i][0];
        for(auto j = 0; j<matrix[i].size(); j++)
        {
            if(matrix[i][j]> max)
            {
                max = matrix[i][j];
            }
        }
        max_elements.push_back(max);
    }
}



int main() {
    srand(time(NULL));
    const short matrix_cols_rows = 10;
    
    
    std::vector<std::vector<short>> matrix(matrix_cols_rows , std::vector<short> (matrix_cols_rows));
    
    std::vector<short> max_elements;
    
    make_matrix(matrix);
    
    out_matrix(matrix);
    
    found_max_make_arr(matrix, max_elements);
    
    out_max(max_elements);
}
