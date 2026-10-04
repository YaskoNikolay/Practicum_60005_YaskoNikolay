#include <iostream>
#include <exception>
#include <cstddef>

int **matr_new(const size_t n)
{
    try
    {
        return new int *[n];
    }
    catch (...)
    {
        throw std::exception();
    }
}
int *arr_new(const size_t n)
{
    try
    {
        return new int[n];
    }
    catch (...)
    {
        throw std::exception();
    }
}
void del_matr(int **matr, size_t n)
{
    if (matr)
    {
        for (size_t i = 0; i < n; i++)
        {
            delete[] matr[i];
        }
        delete[] matr;
    }
}
int main()
{
    const int invalid_input = 1;
    const int memory_error = 2;
    size_t a = 0;
    size_t b = 0;
    std::cin >> a >> b;
    if (std::cin.fail())
    {
        std::cerr << "Error: invalid input\n";
        return invalid_input;
    }
    int **matr = nullptr;
    try
    {
        matr = matr_new(a);
        for (size_t i = 0; i < a; i++)
        {
            matr[i] = nullptr;
        }
        for (size_t i = 0; i < a; i++)
        {
            matr[i] = arr_new(b);
        }
    }
    catch (...)
    {
        std::cerr << "error";
        del_matr(matr, a);
        return memory_error;
    }
    for (size_t i = 0; i < a; i++)
    {
        for (size_t j = 0; j < b; j++)
        {
            std::cin >> matr[i][j];
            if (std::cin.fail())
            {
                std::cerr << "error";
                del_matr(matr, a);
                return invalid_input;
            }
        }
    }
    for (size_t j = 0; j < b; j++)
    {
        for (size_t i = 0; i < a; i++)
        {
            std::cout << matr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    del_matr(matr, a);
    return 0;
}
