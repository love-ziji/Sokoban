#define _MAP_H__
#ifdef  _MAP_H__

#include<iostream>
#include<fstream>
using namespace std;
#define M 10
#define N 11

class Map
{
public:
	Map() {};
	~Map() {};
	void ReadMapFile(int map[M][N], int size, const char* filename);
};

#endif