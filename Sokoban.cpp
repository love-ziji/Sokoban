#include<iostream>
#include<string.h>
using namespace std;
#include"Map.h"
#include"Game.h"
#pragma warning (disable:4996)
#define M 10
#define N 11

int main()

{
	Map _map;
	int map[M][N];
	char filename[] = "map/map_";
	int n;

	while (1) {
		cout << "请选择关卡（小于6的正整数）：";
		cin >> n;
		if (n > 0 && n < 6)
			break;
	}

	while (n < 6)
	{
		char buffer[80];
		sprintf(buffer, "%s%d", filename, n);
		strcat(buffer, ".txt");
		_map.ReadMapFile(map, N, buffer);
		Game game;
		int step = 0;
		int OldMap[M][N];
		memcpy(OldMap, map, M * N * 4);

		do {
			system("cls");
			game.Draw(map, n);
			int ch = _getch();
			if (ch == 82 || ch == 114)
				memcpy(map, OldMap, M * N * 4);
			else {
				ch = _getch();
				step = game.Move(map, ch);
			}
		} while (game.Judge(map));

		n++;
		cout << "成功!" << endl;
		cout << "共走：" << step << "步" << endl;
		system("pause");
	}

	return 0;
}