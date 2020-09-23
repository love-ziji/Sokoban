#include "Game.h"

int Game::Move(int map[M][N], int ch)
{
	static int step = 0;
	int offsetx = 0;
	int offsety = 0;

	switch (ch)
	{
	case 72:
		offsetx = -1;
		offsety = 0;
		if (Push(map, offsetx, offsety) == 1)
			step++;
		break;
	case 80:
		offsetx = 1;
		offsety = 0;
		if (Push(map, offsetx, offsety) == 1)
			step++;
		break;
	case 75:
		offsetx = 0;
		offsety = -1;
		if (Push(map, offsetx, offsety) == 1)
			step++;
		break;
	case 77:
		offsetx = 0;
		offsety = 1;
		if (Push(map, offsetx, offsety) == 1)
			step++;
		break;
	default:
		break;
	}
	return step;
}

void Game::Draw(int map[M][N], int c)
{
	cout << "*************************第 " << c << " 关*************************" << endl;
	cout << "***************** 重新开始当前关卡：R\\r *****************" << endl;
	cout << endl;

	for (int i = 0; i < M; i++)
	{
		cout << "		  ";
		for (int j = 0; j < N; j++)
		{
			switch (map[i][j])
			{
			case 0:
				cout << "  ";//空地
				break;
			case 1:
				cout << "■";//墙壁
				break;
			case 2:
				cout << "♀";//人物
				posX = i;
				posY = j;
				break;
			case 3:
				cout << "□";//箱子
				break;
			case 4:
				cout << "○";//终点
				break;
			case 5:
				cout << "♀";//人+终点
				break;
			case 6:
				cout << "★";//箱子+终点
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}

int Game::Judge(int map[M][N])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j]==4 || map[i][j] == 5)
				return 1;
		}
	}

	return 0;
}

int Game::Push(int map[M][N], int offsetX, int offsetY)
{
	Postion(map);
	if (map[posX + offsetX][posY + offsetY] == 0) //下一格为空地
	{
		if (map[posX][posY] == 5) //当前格为人+终点
			map[posX][posY] = 4;
		else
			map[posX][posY] = 0;

		map[posX + offsetX][posY + offsetY] = 2; //下一格变为人
		
		posX += offsetX;
		posY += offsetY;
	}
	else if (map[posX + offsetX][posY + offsetY] == 3) //下一格为箱子
	{
		if (map[posX + offsetX * 2][posY + offsetY * 2] == 0
			|| map[posX + offsetX * 2][posY + offsetY * 2] == 4) //下两格为空地/终点
		{
			if (map[posX][posY] == 5) //当前格为人+终点
				map[posX][posY] = 4;
			else
				map[posX][posY] = 0;

			map[posX + offsetX][posY + offsetY] = 2; //下一格变为人

			if (map[posX + offsetX * 2][posY + offsetY * 2] == 4) //下两格为终点
				map[posX + offsetX * 2][posY + offsetY * 2] = 6;
			else
				map[posX + offsetX * 2][posY + offsetY * 2] = 3;

			posX += offsetX;
			posY += offsetY;
		}
	}
	else if (map[posX + offsetX][posY + offsetY] == 4) //下一格是终点
	{
		if (map[posX][posY] == 5) //当前格为人+终点
			map[posX][posY] = 4;
		else
			map[posX][posY] = 0;

		map[posX + offsetX][posY + offsetY] = 5; //下一格变为人+终点

		posX += offsetX;
		posY += offsetY;
	}
	else if (map[posX + offsetX][posY + offsetY] == 6) //下一格是箱子+终点
	{
		if (map[posX + offsetX * 2][posY + offsetY * 2] == 0
			|| map[posX + offsetX * 2][posY + offsetY * 2] == 4) //下两格为空地/终点
		{
			if (map[posX][posY] == 5) //当前格为人+终点
				map[posX][posY] = 4;
			else
				map[posX][posY] = 0;

			map[posX + offsetX][posY + offsetY] = 5; //下一格变为人+终点

			if (map[posX + offsetX * 2][posY + offsetY * 2] == 4) //下两格为终点
				map[posX + offsetX * 2][posY + offsetY * 2] = 6;
			else
				map[posX + offsetX * 2][posY + offsetY * 2] = 3;

			posX += offsetX;
			posY += offsetY;
		}
	}
	else                                                          //人物不能移动
		return 0;

	return 1;
}

void Game::Postion(int map[M][N])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 2)
			{
				posX = i;
				posY = j;
			}
		}
	}
}