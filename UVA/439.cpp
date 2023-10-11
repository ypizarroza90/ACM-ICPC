#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>point;
#define limit 8
int M[8][8];

int knigth_move(point x, point y){
	int move_x[] = {1,-1,2,2,1,-1,-2,-2};
	int move_y[] = {2,2,1,-1,-2,-2,1,-1};
	queue<point> cola;
	memset(M,-1, sizeof(M));
	cola.push(x);
	M[x.first][x.second] = 0;
	while(!cola.empty()){
		point tmp = cola.front(); cola.pop();
		int _x = tmp.first;
		int _y = tmp.second;
		if(y == tmp) return M[_x][_y];
		for(int i=0;i<8;i++) {
			int __x = _x + move_x[i];
			int __y = _y + move_y[i];
			if(__x >= 0 && __x <limit && __y >= 0 && __y<limit && M[__x][__y] == -1) {
				cola.push(make_pair(__x,__y));
				M[__x][__y] = M[_x][_y] + 1;
			}
		}
	}
	return -1;
}
string ini, fin;
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>ini>>fin){
		point a = make_pair(ini[0]-'a', ini[1]-'1');
		point b = make_pair(fin[0]-'a', fin[1]-'1');
		int ans = knigth_move(a, b);
		cout<<"To get from "<<ini<<" to "<<fin<<" takes "<<ans<<" knight moves.\n";
	}
	return 0;
}

