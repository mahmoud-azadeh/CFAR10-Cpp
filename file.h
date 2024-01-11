#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include<ctime>
#include <cstdint>
#include<fstream>

template <typename T, typename U>
class file
{
public:
	void write_binary(std::vector < std::vector<U>> data, std::string full_path);
	void write_binary(std::vector<U> data, std::string full_path);
};

template <typename T, typename U>
void file<T, U>::write_binary(std::vector < std::vector<U>> data, std::string full_path)
{
	std::ofstream ofile(full_path, std::ios::out | std::ios::binary);
	
	uint32_t dim1 = data.size();
	uint32_t dim2 = data[0].size();
	T aux;

	if (ofile.is_open())
	{		
		ofile.write((char*)&dim1, sizeof(dim1));
		ofile.write((char*)&dim2, sizeof(dim2));
		for (int i = 0; i < dim1; i++)
			for (int j = 0; j < dim2; j++)
			{
				aux = T(data[i][j]);
				ofile.write((char*)&aux, sizeof(T));
			}

		ofile.close();
	}
	return;
}
template <typename T, typename U>
void file<T, U>::write_binary(std::vector<U> data, std::string full_path)
{
	std::ofstream ofile(full_path, std::ios::out | std::ios::binary);
	
	uint32_t dim1 = data.size();
	uint32_t dim2 = 1;
	T aux;
	if (ofile.is_open())
	{
		ofile.write((char*)&dim1, sizeof(dim1));
		ofile.write((char*)&dim2, sizeof(dim2));

		for (int i = 0; i < dim1; i++)
		{
			aux = T(data[i]);
			ofile.write((char*)&aux, sizeof(T));
		}

		ofile.close();
	}
	return;
}