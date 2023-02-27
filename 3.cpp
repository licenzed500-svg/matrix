//вариант 6 задача 8

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


void out_motors(std::vector<short> &motors)
{
    for(auto i = 0; i<motors.size(); i++)
    {
        std::cout << "\n" << motors[i] << "\n";
    }
}

void out_most_powerful(std::vector<short> &motors)
{
    short min = motors[0];
    {
        for(auto i =0; i<motors.size(); i++)
        {
            if(motors[i] > min)
            {
                min = motors[i];
            }
        }
    }
    std::cout << min;
}

void make_matrix(std::vector<std::vector<short>> &matrix)
{
    const short min_power = 100;
    const short max_power = 1000;
    const short min_category = 1;
    const short max_category = 4;
    for(auto i = 0; i<matrix.size(); i++)
    {
        for(auto j = 0; j<matrix[i].size(); j++)
        {
            if(i==0)
            {
                matrix[i][j] = min_power + rand() % (max_power-min_power);
            }
            else
            {
                matrix[i][j] = min_category + rand() % (max_category-min_category);
            }
        }
    }
}



void found_most_powerful(std::vector<std::vector<short>> &matrix, std::vector<short> &category_three_motors)
{
    for(auto i = 0; i<matrix.size(); i++)
    {
        if(matrix[1][i] == 3)
        {
            category_three_motors.push_back(matrix[0][i]);
        }
    }
}



int main() {
    srand(time(NULL));
    const short matrix_rows = 10;
    const short matrix_cols = 2;
    
    
    std::vector<std::vector<short>> matrix(matrix_cols , std::vector<short> (matrix_rows));
    std::vector<short> category_three_motors;
    
    make_matrix(matrix);
    
    out_matrix(matrix);
    found_most_powerful(matrix, category_three_motors);
    out_motors(category_three_motors);
    out_most_powerful(category_three_motors);
}
