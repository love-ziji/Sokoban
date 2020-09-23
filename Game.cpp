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
	cout << "*************************�� " << c << " ��*************************" << endl;
	cout << "***************** ���¿�ʼ��ǰ�ؿ���R\\r *****************" << endl;
	cout << endl;

	for (int i = 0; i < M; i++)
	{
		cout << "		  ";
		for (int j = 0; j < N; j++)
		{
			switch (map[i][j])
			{
			case 0:
				cout << "  ";//�յ�
				break;
			case 1:
				cout << "��";//ǽ��
				break;
			case 2:
				cout << "��";//����
				posX = i;
				posY = j;
				break;
			case 3:
				cout << "��";//����
				break;
			case 4:
				cout << "��";//�յ�
				break;
			case 5:
				cout << "��";//��+�յ�
				break;
			case 6:
				cout << "��";//����+�յ�
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
	if (map[posX + offsetX][posY + offsetY] == 0) //��һ��Ϊ�յ�
	{
		if (map[posX][posY] == 5) //��ǰ��Ϊ��+�յ�
			map[posX][posY] = 4;
		else
			map[posX][posY] = 0;

		map[posX + offsetX][posY + offsetY] = 2; //��һ���Ϊ��
		
		posX += offsetX;
		posY += offsetY;
	}
	else if (map[posX + offsetX][posY + offsetY] == 3) //��һ��Ϊ����
	{
		if (map[posX + offsetX * 2][posY + offsetY * 2] == 0
			|| map[posX + offsetX * 2][posY + offsetY * 2] == 4) //������Ϊ�յ�/�յ�
		{
			if (map[posX][posY] == 5) //��ǰ��Ϊ��+�յ�
				map[posX][posY] = 4;
			else
				map[posX][posY] = 0;

			map[posX + offsetX][posY + offsetY] = 2; //��һ���Ϊ��

			if (map[posX + offsetX * 2][posY + offsetY * 2] == 4) //������Ϊ�յ�
				map[posX + offsetX * 2][posY + offsetY * 2] = 6;
			else
				map[posX + offsetX * 2][posY + offsetY * 2] = 3;

			posX += offsetX;
			posY += offsetY;
		}
	}
	else if (map[posX + offsetX][posY + offsetY] == 4) //��һ�����յ�
	{
		if (map[posX][posY] == 5) //��ǰ��Ϊ��+�յ�
			map[posX][posY] = 4;
		else
			map[posX][posY] = 0;

		map[posX + offsetX][posY + offsetY] = 5; //��һ���Ϊ��+�յ�

		posX += offsetX;
		posY += offsetY;
	}
	else if (map[posX + offsetX][posY + offsetY] == 6) //��һ��������+�յ�
	{
		if (map[posX + offsetX * 2][posY + offsetY * 2] == 0
			|| map[posX + offsetX * 2][posY + offsetY * 2] == 4) //������Ϊ�յ�/�յ�
		{
			if (map[posX][posY] == 5) //��ǰ��Ϊ��+�յ�
				map[posX][posY] = 4;
			else
				map[posX][posY] = 0;

			map[posX + offsetX][posY + offsetY] = 5; //��һ���Ϊ��+�յ�

			if (map[posX + offsetX * 2][posY + offsetY * 2] == 4) //������Ϊ�յ�
				map[posX + offsetX * 2][posY + offsetY * 2] = 6;
			else
				map[posX + offsetX * 2][posY + offsetY * 2] = 3;

			posX += offsetX;
			posY += offsetY;
		}
	}
	else                                                          //���ﲻ���ƶ�
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