﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>
#include <mmsystem.h>
#include <random>
#pragma comment(lib,"winmm.lib")

using namespace std;

#define PLAYER_BOTTOM_Y 12
#define OBSTACLE_BOTTOM_Y 20
#define OBSTACLE_BOTTOM_X 45

//콘솔 창을 만드는 함수
void SetConsoleView()
{
	system("mode con:cols=100 lines=25|title Going to EV");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	
	/*
	HWND hWnd = GetConsoleWindow();

	HBITMAP hImage,holdBitmap;

	HDC hDC = GetDC(hWnd);
	HDC hMemDC = CreateCompatibleDC(hDC);

	hImage = (HBITMAP)LoadImage(NULL, TEXT("background.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	holdBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(hDC, 0, 0, 100, 25, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, holdBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);
	ReleaseDC(hWnd, hDC);
	*/

}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

//플레이어를 그리는 함수
void DrawPlayer(int playerY)
{
	GotoXY(0, playerY);
	static bool legFlag = true;
	cout<<"        $$$$$$$ \n";
	cout<<"       $$     $$\n";
	cout<<"        $$$$$$$\n";
	cout<<"          $$$\n";
	cout<<"        $$$$$$$\n";
	cout<<"         $$$$$\n";
	cout<<"          $$$\n";
	cout<<"        $     $ \n";
	cout<<"        $     $ \n";
	cout<<"        $     $ \n";
	cout<<"        $     $ \n";
	if (legFlag)
	{
		cout<<"        $     $$$ \n";
		legFlag = false;
	}
	else
	{
		cout<<"        $$$     $ \n";
		legFlag = true;
	}
}

//나무를 그리는 함수
void DrawObstacle(int OBSTACLEX, int prob)
{
	switch (prob)
	{
	case 1:
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y);
		cout << "$$$$$$$$$$$$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 1);
		cout << "$           $";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 2);
		cout << "$$$$$$$$$$$$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 3);
		cout << "$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 4);
		cout << "$$";
		break;
	case 2:
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y);
		cout << "$$$$$$$$$$$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 1);
		cout << "$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 2);
		cout << "$$$$$$$$$$$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 3);
		cout << "          $$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 4);
		cout << "$$$$$$$$$$$$";
		break;
	case 3:
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y);
		cout << "     $$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 1);
		cout << "   $$   $$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 2);
		cout << "  $$$   $$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 3);
		cout << " $$$$   $$$$";
		GotoXY(OBSTACLEX, OBSTACLE_BOTTOM_Y + 4);
		cout << "$$$$$   $$$$$";
		break;
	}
}


//(v2.0) 충돌 했을때 게임오버 그려줌
void DrawGameOver()
{
	system("cls");
	int x = 18;
	int y = 8;
	GotoXY(x, y);
	cout<<"===========================";
	GotoXY(x, y + 1);
	cout<<"======G A M E O V E R======";
	GotoXY(x, y + 2);
	cout<<"===========================";
	GotoXY(x, y + 5);

	cout<<"\n\n\n\n\n\n\n\n\n";
	system("pause");
}

//(v2.0) 충돌했으면 true, 아니면 false
bool isCollision(const int OBSTACLEX, const int playerY, const int life)
{
	//트리의 X가 공룡의 몸체쪽에 있을때,
	//공룡의 높이가 충분하지 않다면 충돌로 처리
	GotoXY(0, 0);
	cout << "OBSTACLEX : " << OBSTACLEX << " playerY : " << playerY << " life : " << life; //이런식으로 적절한 X, Y를 찾습니다.

	if (OBSTACLEX <= 8 && OBSTACLEX >= 4 &&
		playerY > 8)
	{
		return true;
	}
	return false;
}

int main()
{

	SetConsoleView();

	while (true)		//(v2.0) 게임 루프
	{
		//게임 시작시 초기화
		bool isJumping = false;
		bool isBottom = true;
		const int gravity = 3;

		int playerY = PLAYER_BOTTOM_Y;
		int OBSTACLEX = OBSTACLE_BOTTOM_X;

		int life = 5;
		clock_t start, curr;	//점수 변수 초기화
		start = clock();		//시작시간 초기화

		random_device prob;
		mt19937 gen(prob());
		uniform_int_distribution<int> dis(1, 3);
		int check = dis(gen);

		while (true)	//한 판에 대한 루프
		{

			//(v2.0) 충돌체크 트리의 x값과 공룡의 y값으로 판단
			if (isCollision(OBSTACLEX, playerY,life)) {
				life--;
				OBSTACLEX = -10;
			}

			//스페이스키가 눌렸고, 바닥이 아닐때 점프
			if (GetKeyDown() == ' ' && isBottom)
			{
				isJumping = true;
				isBottom = false;
			}

			//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
			if (isJumping)
			{
				playerY -= gravity;
			}
			else
			{
				playerY += gravity;
			}

			//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
			if (playerY >= PLAYER_BOTTOM_Y)
			{
				playerY = PLAYER_BOTTOM_Y;
				isBottom = true;
			}

			//나무가 왼쪽으로 (x음수) 가도록하고
			//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
			OBSTACLEX -= 3;
			if (OBSTACLEX <= 0)
			{
				OBSTACLEX = OBSTACLE_BOTTOM_X;
				check = dis(gen);
			}

			//점프의 맨위를 찍으면 점프가 끝난 상황.
			if (playerY <= 3)
			{
				isJumping = false;
			}

			DrawPlayer(playerY);		//draw player
			DrawObstacle(OBSTACLEX, check);
				
			curr = clock();			//현재시간 받아오기

			if (((curr - start) / CLOCKS_PER_SEC) >= 30 || life ==0) {	 //게임종료
				break;
			}
			
			Sleep(60);
			system("cls");	//clear		

		}
		DrawGameOver();
		break;
	}

	return 0;
}