#include <bits/stdc++.h>

/**
* Exam: 06/07/18
* Time: h*w + q
**/
using namespace std;
int main() {
	
	int h, w;
	scanf("%d%d", &h, &w);
	char grid[h + 1][w + 1];
	
	for(int i = 0; i < h; i++) {
		grid[i][0] = '#';
		scanf("%s", grid[i + 1] + 1);
	}
	for(int j = 1; j <= w; j++)
		grid[0][j] = '#';
	
	int hor[h + 1][w + 1];
	int ver[h + 1][w + 1];
	
	for(int i = 0; i <= h; i++) { 
		memset(hor[i], 0, sizeof(hor[i])); 
		memset(ver[i], 0, sizeof(hor[i])); 
	}
	
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			hor[i][j] = hor[i][j-1] + hor[i-1][j] + (grid[i][j] == '.' && grid[i][j-1] == '.') - hor[i-1][j-1];
			ver[i][j] = ver[i-1][j] + ver[i][j-1] + (grid[i][j] == '.' && grid[i-1][j] == '.') - ver[i-1][j-1];
		}
	}
	
	int q;
	scanf("%d", &q);
	while(q--) {
		int y1, x1, y2, x2;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		int ans  = hor[y2][x2] - hor[y1 - 1][x2] - hor[y2][x1] + hor[y1 - 1][x1];
		ans 	+= ver[y2][x2] - ver[y2][x1 - 1] - ver[y1][x2] + ver[y1][x1 - 1];
		printf("%d\n", ans);
	}
	
	
}
