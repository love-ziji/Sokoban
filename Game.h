#define _GAEM_H__
#ifdef  _GAEM_H__

#include <iostream>
using namespace std;
#include <conio.h>
#define M 10
#define N 11

class Game
{
public:
	int Move(int map[M][N], int ch);
	void Draw(int map[M][N], int c);
	int Judge(int map[M][N]);
private:
	int Push(int map[M][N], int offsetX, int offsetY);
	void Postion(int map[M][N]);
	int posX;
	int posY;
};

#endif