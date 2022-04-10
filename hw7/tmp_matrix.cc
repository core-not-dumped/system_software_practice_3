#include "matrix.h"

MATRIX::MATRIX(void)
{
    n_row = 0;
    n_col = 0;
    data_array.clear();
}

MATRIX::MATRIX(size_t row_size, size_t col_size)
{
    n_row = row_size;
    n_col = col_size;

    data_array.resize(row_size * col_size, 0);
}

MATRIX::MATRIX(std::vector<int> data, size_t row_size, size_t col_size)
{
    size_t array_size = data.size();

    n_row = row_size;
    n_col = col_size;

    data_array.resize(array_size);

    for (size_t i=0; i<array_size; i++) data_array.at(i) = data.at(i);
}

std::string MATRIX::to_string() const
{
    std::string result = "{";

    for (size_t row = 0; row < n_row; row++) {

        for (size_t col = 0; col < n_col; col ++) {

            if (col == 0) result += "{";

            result += std::to_string(data_array.at(row * n_col + col));

            if (col != (n_col - 1)) result += ", ";
        }

        result += "}";

        if (row != (n_row-1)) result += ", ";
        else result += "}";
    }

    return result;
}

size_t MATRIX::get_size() const {return n_row * n_col;}

std::vector <size_t> MATRIX::get_dimension() const
{
    std::vector <size_t> dimension(2, 0);

    dimension.at(0) = n_row;
    dimension.at(1) = n_col;

    return dimension;
}

int MATRIX::at(size_t row, size_t col) const
{
    return data_array[row * n_col + col];
}

void MATRIX::at(size_t row, size_t col, int data)
{
    data_array[row * n_col + col] = data;
    return;
}

MATRIX MATRIX::at(std::string range) const
{
    size_t com_pos = range.find(',');
    
    size_t dim1_s, dim1_f;
    size_t dim2_s, dim2_f;

    std::string left = range.substr(0, com_pos);
    if(left.find(':') != std::string::npos)
    {
        size_t col_pos = left.find(':');

        if(col_pos == 0)
        {
            dim1_s = 0;
            dim1_f = n_row;
        }
        else
        {
            dim1_s = stoi(left.substr(0, col_pos));
            dim1_f = stoi(left.substr(col_pos + 1));
        }
    }
    else
    {
        dim1_s = stoi(left);
        dim1_f = dim1_s + 1;
    }

    std::string right = range.substr(com_pos+1);
    if(right.find(':') != std::string::npos)
    {
        size_t col_pos = right.find(':');

        if(col_pos == 0)
        {
            dim2_s = 0;
            dim2_f = n_col;
        }
        else
        {
            dim2_s = stoi(right.substr(0, col_pos));
            dim2_f = stoi(right.substr(col_pos + 1));
        }
    }
    else
    {
        dim2_s = stoi(right);
        dim2_f = dim2_s + 1;
    }

    std::vector<int> d;
    d.clear();
    for(size_t i = dim1_s;i < dim1_f;i++)
    {
        for(size_t j = dim2_s;j < dim2_f;j++)
            d.push_back((*this).at(i, j));
    }

    MATRIX result(d, dim1_f - dim1_s , dim2_f - dim2_s);
    return result;
}

void MATRIX::at(std::string range, std::vector<int> data)
{
    size_t com_pos = range.find(',');
    
    size_t dim1_s, dim1_f;
    size_t dim2_s, dim2_f;

    std::string left = range.substr(0, com_pos);
    if(left.find(':') != std::string::npos)
    {
        size_t col_pos = left.find(':');

        if(col_pos == 0)
        {
            dim1_s = 0;
            dim1_f = n_row;
        }
        else
        {
            dim1_s = stoi(left.substr(0, col_pos));
            dim1_f = stoi(left.substr(col_pos + 1));
        }
    }
    else
    {
        dim1_s = stoi(left);
        dim1_f = dim1_s + 1;
    }

    std::string right = range.substr(com_pos+1);
    if(right.find(':') != std::string::npos)
    {
        size_t col_pos = right.find(':');

        if(col_pos == 0)
        {
            dim2_s = 0;
            dim2_f = n_col;
        }
        else
        {
            dim2_s = stoi(right.substr(0, col_pos));
            dim2_f = stoi(right.substr(col_pos + 1));
        }
    }
    else
    {
        dim2_s = stoi(right);
        dim2_f = dim2_s + 1;
    }

    int cnt = 0;
    for(size_t i = dim1_s;i < dim1_f;i++)
    {
        for(size_t j = dim2_s;j < dim2_f;j++)
            (*this).at(i, j, data[cnt++]);
    }
}

MATRIX MATRIX::operator [](std::string range)
{
    return (*this).at(range);
}

MATRIX MATRIX::operator +(MATRIX rhs)
{
    std::vector<int> d;
    std::vector<size_t> dim1 = (*this).get_dimension();
    std::vector<size_t> dim2 = rhs.get_dimension();

    if(dim1[0] != dim2[0] || dim1[1] != dim2[1])
    {
        MATRIX result;
        return result;
    }
    
    for(size_t i = 0;i < dim1[0];i++)
    {
        for(size_t j = 0;j < dim1[1];j++)
            d.push_back((*this).at(i, j) + rhs.at(i, j));
    }

    MATRIX result(d, dim1[0], dim1[1]);
    return result;
}

MATRIX MATRIX::operator -(MATRIX rhs)
{
    std::vector<int> d;
    std::vector<size_t> dim1 = (*this).get_dimension();
    std::vector<size_t> dim2 = rhs.get_dimension();

    if(dim1[0] != dim2[0] || dim1[1] != dim2[1])
    {
        MATRIX result;
        return result;
    }
    
    for(size_t i = 0;i < dim1[0];i++)
    {
        for(size_t j = 0;j < dim1[1];j++)
            d.push_back((*this).at(i, j) - rhs.at(i, j));
    }

    MATRIX result(d, dim1[0], dim1[1]);
    return result;
}

MATRIX MATRIX::operator *(MATRIX rhs)
{
    std::vector<int> d;
    std::vector<size_t> dim1 = (*this).get_dimension();
    std::vector<size_t> dim2 = rhs.get_dimension();

    if(dim1[1] != dim2[0])
    {
        MATRIX result;
        return result;
    }
    
    for(size_t i = 0;i < dim1[0];i++)
    {
        for(size_t j = 0;j < dim2[1];j++)
        {
            int sum = 0;
            for(size_t k = 0 ;k < dim1[1]; k++)
            {
                sum += (*this).at(i, k) * rhs.at(k, j);
            }
            d.push_back(sum);
        }
    }

    MATRIX result(d, dim1[0], dim2[1]);
    return result;
}

void MATRIX::operator +=(MATRIX rhs)
{
    (*this) = (*this) + rhs;
}

void MATRIX::operator -=(MATRIX rhs)
{
    (*this) = (*this) - rhs;
}

void MATRIX::operator *=(MATRIX rhs)
{
    (*this) = (*this) * rhs;
}

MATRIX MATRIX::operator +(int rhs)
{
    std::vector<int> d;
    for(size_t i=0;i<n_row;i++)
    {
        for(size_t j=0;j<n_col;j++)
            d.push_back((*this).at(i, j) + rhs);
    }
    MATRIX result(d, n_row, n_col);
    return result;
}

MATRIX MATRIX::operator *(int rhs)
{
    std::vector<int> d;
    for(size_t i=0;i<n_row;i++)
    {
        for(size_t j=0;j<n_col;j++)
            d.push_back((*this).at(i, j) * rhs);
    }
    MATRIX result(d, n_row, n_col);
    return result;
}

MATRIX operator -(MATRIX A, int B)
{
    std::vector<size_t> dim = A.get_dimension();
    std::vector<int> d;
    for(size_t i=0;i<dim[0];i++)
    {
        for(size_t j=0;j<dim[1];j++)
            d.push_back(A.at(i, j) - B);
    }
    MATRIX result(d, dim[0], dim[1]);
    return result;
}

MATRIX operator -(int A, MATRIX B)
{
    std::vector<size_t> dim = B.get_dimension();
    std::vector<int> d;
    for(size_t i=0;i<dim[0];i++)
    {
        for(size_t j=0;j<dim[1];j++)
            d.push_back(A - B.at(i, j));
    }
    MATRIX result(d, dim[0], dim[1]);
    return result;
}

void MATRIX::operator +=(int rhs)
{
    (*this) = (*this) + rhs;
}

void MATRIX::operator -=(int rhs)
{
    (*this) = (*this) - rhs;
}

void MATRIX::operator *=(int rhs)
{
    (*this) = (*this) * rhs;
}

bool MATRIX::operator ==(MATRIX rhs)
{
    for(size_t i=0;i<n_row;i++)
    {
        for(size_t j=0;j<n_col;j++)
        {
            if((*this).at(i,j) != rhs.at(i,j))
                return false;
        }
    }
    return true;
}

bool MATRIX::operator !=(MATRIX rhs)
{
    return !((*this) == rhs);
}







