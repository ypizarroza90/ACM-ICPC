#include <bits/stdc++.h>

#define endl '\n'
#define INF 10000000009
const int MAXN = 200001;

using namespace std;

struct node
{
	long int key;
	int prior,cnt;
	long maxv;
	node *l,*r;
};

typedef node* pnode;

pnode root;
node treap[MAXN];
vector<int> rnd;
int t_cnt;

int cnt(pnode t){return t ? t->cnt : 0;}
long maxv(pnode t){return t ? t->maxv : INT_MIN;}

void update(pnode t){
	if(!t)
		return;
	t->cnt = 1 + cnt(t->l) + cnt(t->r);
	t->maxv = max(t->key, max(maxv(t->l),maxv(t->r)));
}

void split(pnode t, pnode &l, pnode &r, int pos){
	if(!t)
		l = r = NULL;
	else if(pos <= cnt(t->l))
		split(t->l, l, t->l, pos), r = t;
	else
		split(t->r, t->r, r, pos - cnt(t->l)-1), l = t;

	update(t);
}

void merge(pnode &t, pnode l, pnode r){
	if(!l || !r)
		t = l ? l: r;
	else if(l->prior > r->prior)
		merge(l->r,l->r,r), t = l;
	else
		merge(r->l, l, r->l), t = r;

	update(t);
}

void insert(pnode &t, pnode it, int pos){
	if(!t)
		t = it;
	else if(it->prior > t->prior)
		split(t,it->l,it->r, pos), t=it;
	else if(pos <= cnt(t->l))
		insert(t->l, it, pos);
	else
		insert(t->r,it, pos-cnt(t->l)-1);

	update(t);
}

int k_th(pnode &t, int pos){
	if(pos < cnt(t->l))
		return k_th(t->l, pos);
	else if(pos > cnt(t->l))
		return k_th(t->r, pos - cnt(t->l)-1);
	return t->key;
}

void erase(pnode &t, int key){
	if(t->key == key)
		merge(t, t->l, t->r);
	else
		erase(key < t->key ? t->l : t->r, key);
}

void output(pnode t){
	if(!t) return;
	output(t->l);
	cout<<t->key<<' ';
	output(t->r);
}

void insert(int pos,int val){
	pnode it = &treap[t_cnt];
	it->key = val;
	it->prior = rnd[t_cnt];
	++t_cnt;
	insert(root, it,pos);
}

int query(int i, int j){
	pnode l1, r1;
	split(root, l1, r1, j+1);
	pnode l2, r2;
	split(l1, l2, r2, i);
	int ans = maxv(r2);
	pnode t;
	merge(t, l2, r2);
	merge(root, t, r1);
	update(root);
	return ans;
}

int cas,i,j;
char op;
int main()
{
	 for (int i = 0; i < MAXN; i++)
        rnd.push_back(i);
    	random_shuffle(rnd.begin(), rnd.end());
	cin>>cas;
	while(cas--){
		cin>>op>>i>>j;

		switch(op){
			case 'A':
				insert(j-1, i);
				break;
			default:
				cout<<query(i-1,j-1)<<endl;
				break;
		}
	}
	return 0;
}

