#include <stdio.h>
int main() {
	int x, y, c, d,result,cleaner=0; 
	result = 0;
	int room[2][51][51];
	scanf("%d %d %d", &y, &x, &c);
	for (int h = 0; h < y; h++)
	{
		for (int i = 0; i < x; i++)
		{
			room[1][h][i] = 0;
		}
	}
	for (int h = 0; h < y; h++)
	{
		for (int i = 0; i < x; i++)
		{
			scanf(" %d", &room[0][h][i]);
		}
	}
	for (int h = 0; h < y; h++)
	{
		if (room[0][h][0] == -1)
		{
			//첫번째 공기청정기 위치 파악
			cleaner = h;
			break;
		}
	}
	for (int h = 0; h < c; h++)
	{  //확산
		for (int xx = 0; xx < x; xx++)
		{
			for (int yy = 0; yy < y; yy++)
			{
				int k = room[0][yy][xx];
				if (room[0][yy][xx] != -1) {
					if (xx >= 1&& room[0][yy ][xx- 1]!=-1)
					{//좌
						room[1][yy][xx - 1] += room[0][yy][xx] / 5;
						k -=room[0][yy][xx] / 5;
					}
					if (xx < x-1 && room[0][yy][xx + 1] != -1)
					{//우
						room[1][yy][xx + 1] +=room[0][yy][xx] / 5;
						k -= room[0][yy][xx] / 5;
					}
					if (yy >= 1&& room[0][yy - 1][xx] != -1)
					{//하
						room[1][yy - 1][xx] +=room[0][yy][xx] / 5;
						
						k -= room[0][yy][xx] / 5;
					}
					if (yy < y-1&& room[0][yy + 1][xx ] != -1)
					{//상
						
						room[1][yy + 1][xx] +=room[0][yy][xx] / 5;
						k -=room[0][yy][xx] / 5;
					}
					room[1][yy][xx] += k ;//중앙에다 나머지
				}
			}
		}
		//공기청정기
		room[1][cleaner][0] = -1;
		room[1][cleaner+1][0] = -1;
		//2번 맵에서 1번 맵으로 카피 
		for (int h = 0; h < y; h++)
		{
			for (int i = 0; i < x; i++)
			{
				room[0][h][i] = room[1][h][i];
			}
		}
		//2번 맵 초기화
		for (int h = 0; h < y; h++)
		{
			for (int i = 0; i < x; i++)
			{
				room[1][h][i] =0;
			}
		}
		//위쪽 공기청정기
		for (int i = cleaner-1; i >0; i--)//서쪽 면
		{
			room[0][i][0] = room[0][i-1][0];
		}
		for (int i = 0; i < x-1; i++)//북쪽 면
		{
			room[0][0][i] = room[0][0][i+1];
		}
		for (int i = 0; i < cleaner; i++)//동쪽 면
		{
			room[0][i][x-1] = room[0][i+1][x - 1];
		}
		for (int i = x-1; i > 1; i--)//남쪽 면
		{
			room[0][cleaner][i] = room[0][cleaner][i-1];
		}
		room[0][cleaner][1] = 0;//정화
		//아래쪽 공기청정기
		for (int i = cleaner+2; i < y-1; i++)//서쪽 면
		{
			room[0][i][0] = room[0][i + 1][0];
		}	
		for (int i = 0; i < x - 1; i++)//남쪽 면
		{
			
			room[0][y-1][i] = room[0][y-1][i + 1];
		}
		for (int i = y-1; i > cleaner+1; i--)//동쪽 면
		{
			room[0][i][x-1] = room[0][i-1][x-1];
		}
		for (int i = x-1; i > 1; i--)//북쪽 면
		{
			room[0][cleaner +1][i] = room[0][cleaner +1][i-1];
		}
		room[0][cleaner + 1][1] = 0;//정화
	}
	for (int h = 0; h < y; h++)
	{
		for (int i = 0; i < x; i++)
		{
			result+=room[0][h][i];
		}
	}
	result += 2;//공기청정기에 의해 계산된 -2 복구
	printf("%d", result);
}