#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'
const int MAXN = 50001;

struct node
{
	int cnt,prio;
	long int key, ans, sum, lsum, rsum; // lsum best sum that init in the first element, rsum best sum that end in the last element
	node *l, *r;
	bool rev;
};

typedef node* pnode;

pnode root;
node treap[MAXN];
vector<int> rnd;
int t_cnt;

int cnt(pnode t){
	return t ? t->cnt : 0;
}

void update_sz(pnode t){
	if(t)
		t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void push(pnode &t){
    if(t && t->rev){
        update_sz(t);
		t->rev ^= 1;
		swap(t->l, t->r);
		if(t->l) t->l->rev ^= 1;
		if(t->r) t->r->rev ^= 1;
    }
}

void reset(pnode t){
	if(t){
		t->ans = t->key;
		t->sum = t->key;
		t->lsum = t->key;
		t->rsum = t->key;
	}
}

void combine(pnode &t, pnode l, pnode r){
	if(!l || !r)
		return void(t = l ? l : r);
	t->ans = max(l->rsum + r->lsum, max(l->ans, r->ans));
	t->lsum = max(l->lsum, l->sum + r->lsum);
	t->rsum = max(r->rsum, r->sum + l->rsum);
	t->sum = l->sum + r->sum;

}

void update_node(pnode t){
	if(!t) return;
	reset(t);
	combine(t, t->l, t);
	combine(t, t, t->r);
}


void split(pnode t, pnode &l, pnode &r, int pos){
	if(!t)
		return void(l = r = NULL);
	push(t);
	if(pos <= cnt(t->l))
		split(t->l, l, t->l, pos), r = t;
	else
		split(t->r, t->r, r, pos - cnt(t->l)-1), l = t;

	update_sz(t);
	update_node(t);

}

void merge(pnode &t, pnode l, pnode r){
	push(l); push(r);
	if(!l || !r)
		t = l ? l: r;
	else if(l->prio > r->prio)
		merge(l->r,l->r,r), t = l;
	else
		merge(r->l, l, r->l), t = r;

	update_sz(t);
	update_node(t);
}

void insert(pnode &t, pnode it, int pos){
	if(!t)
		t = it;
	else if(it->prio > t->prio)
		split(t,it->l,it->r, pos), t=it;
	else if(pos <= cnt(t->l))
		insert(t->l, it, pos);
	else
		insert(t->r,it, pos-cnt(t->l)-1);

	update_sz(t);
	update_node(t);
}

int k_th(pnode &t, int pos){
	push(t);
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
	push(t);
	output(t->l);
	cout<<t->key<<' ';
	output(t->r);
}

void insert(int pos,int val){
	pnode it = &treap[t_cnt];
	it->key = val;
	it->sum = val;
	it->lsum = val;
	it->rsum = val;
	it->prio = rnd[t_cnt];
	it->rev = false;
	++t_cnt;
	insert(root, it,pos);
}

long int query(pnode &t, int l, int r){
	pnode l1, r1;
	split(t, l1, r1, l);
	pnode l2, r2;
	split(r1, l2, r2, r - l + 1);
	long int ans = l2->ans;
	merge(r1,l2,r2);
	merge(t,l1, r1);
	return ans;
}

int N ,M;
int value, x, y;
string cad;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	 for (int i = 0; i < MAXN; i++)
        rnd.push_back(i);
    random_shuffle(rnd.begin(), rnd.end());

    cin>>N;
    for(int i=0;i<N;i++){
    	cin>>value;
    	insert(i, value);
    }
    cin>>M;
    while(M--){
    	cin>>x>>y;
    	cout<<query(root, x-1, y-1)<<endl;
    }

	return 0;
}

