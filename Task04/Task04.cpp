#define _CRT_SECURE_NO_WARNINGS

// Task04.cpp: определяет точку входа для консольного приложения.
//

#include <stdio.h>
#include <float.h>
#include <vector>
#include <numeric>
#include <fstream>

// искомая функция
double func(int count, std::vector<int>& vi, int v, std::vector<int>& ui)
{
	double y = 0.0;
	for (int i = 0; i < count; i++)
	{
		if (ui[i] == 0) return DBL_MAX ;
		double z = static_cast<double>(vi[i]) / v - static_cast<double>(vi[i]) / ui[i];
		y += z * z;
	}
	return y;
}

int main(int argc, char* argv[])
{
	int count;
	int v;
	double y;
	std::vector<int> vi;
	std::vector<int> ui;
	char* inputFileName;
	char* outputFileName;

	// Получаем параметры - имена файлов
	inputFileName = argv[1];
	outputFileName = argv[2];

	/* Заполняем массив числами */
	std::ifstream ifs(inputFileName, std::ifstream::in);
	ifs >> count;
	ifs >> v;
	for (int i = 0; i < count; i++)
	{
		int x;
		ifs >> x;
		vi.push_back(x);
	}
	ifs.close();

	ui.push_back(v);
	for (int i = 1; i < count; i++) ui.push_back(0);
	y = func(count, vi, v, ui);
	std::vector<int> xi(count);
	std::copy(ui.begin(), ui.end(), xi.begin());
	for (;;)
	{
		xi[xi.size() - 1]--;
		if (xi[xi.size() - 1] == -1)
		{
			xi.pop_back();
			if (xi.size() == 0) break;
			continue;
		}

		for (int i = xi.size(); i < count; i++)
			xi.push_back(v - std::accumulate(xi.begin(), xi.end(), 0));

		double y1 = func(count, vi, v, xi);
		if (y1 < y)
		{
			y = y1;
			std::copy(xi.begin(), xi.end(), ui.begin());
		}
	}

	std::ofstream ofs(outputFileName, std::ofstream::out);
	for (int i = 0; i < count; i++)
	{
		ofs << ui[i] << '\n';
	}
	ofs.close();

	return 0;
}
