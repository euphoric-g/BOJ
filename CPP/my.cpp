#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> board;
bool visited[300][300];

const int x_grad[4] = { -1, 0, 0, 1 };
const int y_grad[4] = { 0, -1, 1, 0 };

void dfs(int y, int x){
	visited[y][x] = true;
	
	for(int i = 0; i < 4; i++){
		int there_x = x + x_grad[i], there_y = y + y_grad[i];
		if(there_x < 1 || there_x >= m - 1|| there_y < 1 || there_y >= n - 1) continue;
		
		if(board[there_y][there_x] > 0 && !visited[there_y][there_x]) 
			dfs(there_y, there_x);
	}
}

void melt_ice(){
	vector<vector<int>> here = board;
	for(int i = 1; i < n - 1; i++){
		for(int j = 1; j < m - 1; j++){
			if(here[i][j] == 0) continue;
			
			int count = 0;
			for(int k = 0; k < 4; k++){
				int there_x = j + x_grad[i], there_y = i + y_grad[i];
				if(there_x < 1 || there_x >= m - 1 || there_y < 1 || there_y >= n - 1) continue;
				
				if(here[there_y][there_x] == 0) count++;
			}
			board[i][j] = count;
		}
	}
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	cin >> n >> m;
	board.resize(n);
	for(int i = 0; i < n; i++){
		board[i].resize(m);
		for(int j = 0; j < m; j++) cin >> board[i][j];
	}
	
	int ans = 0;
	while(1){
		memset(visited, false, sizeof(visited));
		int island = 0;
		for(int i = 1; i < n - 1; i++){
			for(int j = 1; j < m - 1; j++){
				if(!visited[i][j] && board[i][j]){
					island++;
					dfs(i, j);
				}
			}
		}
		
		if(island > 1) break;
		else if(island == 0){
			ans = 0;
			break;
		}
		
		melt_ice(); ans++;
	}
	cout << ans << "\n";
	return 0;
}