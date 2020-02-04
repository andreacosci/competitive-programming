#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;

vector<ll> sum;
int n,m;

void print_tree() {
	for(auto x : sum)
		cout << x << " ";
	cout << '\n';
}
 
int Update(int now, int L, int R, int v, int x, int y){
	if(L <= x && y <= R){
		sum[now]+=v;
	} else {
		int mid=(x+y)/2;
		if(L<mid) Update(now*2,L,R,v,x,mid);
		if(mid<R) Update(now*2+1,L,R,v,mid,y);
		long long s = sum[now*2];
		s = min(s,sum[now*2+1]);
		sum[now] += s;
		sum[now*2] -= s;
		sum[now*2+1] -= s;
	}
	return 0;
}
 
long long Query(int now,int L,int R,int x,int y){
	if(L<=x && y<=R)
		return sum[now];
	else{
		int mid=(x+y)>>1;
		long long s = LONG_LONG_MAX;
		if(L<mid)s=min(s,Query(now*2,L,R,x,mid));
		if(mid<R)s=min(s,Query(now*2+1,L,R,mid,y));
		return sum[now]+s;
	}
}
 
int main(){
	int x,y,z;
	char str[256];
	
	scanf("%d",&n);
	int sz = (1 << static_cast<int>(ceil(log2(n))))*2;
	sum = vector<ll>(sz, 0);
	
	for(int i = 0; i < n; i++){
		scanf("%d",&x);
		Update(1, i, i+1, x, 0, n);
		print_tree();
	}
 
	scanf("%d",&m);
	gets(str);
	for(int i=0;i<m;i++){
		if(sscanf(gets(str),"%d%d%d",&x,&y,&z)==3){
			if(x<=y){
				Update(1,x,y+1,z,0,n);
			}else{
				Update(1,x,n,z,0,n);
				Update(1,0,y+1,z,0,n);
			}
		}else{
			if(x<=y){
				printf("%I64d\n", Query(1,x,y+1,0,n));
			}else{
				printf("%I64d\n",min(Query(1,x,n,0,n), Query(1,0,y+1,0,n)));
			}
		}
	}
		
}
