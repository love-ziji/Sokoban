#include "Map.h"

void Map::ReadMapFile(int map[M][N], int size, const char* filename)
{
	ifstream fin(filename, ios::in);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fin >> map[i][j];
		}
	}
	fin.close();
}