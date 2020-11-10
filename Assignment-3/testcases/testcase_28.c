int addself (int q) {
	q = q + 6;
	return q;
}
int multiplicationself(int p){
	p = p * p;
	return p;
}


int main() {
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	a = 8;
	b = 4;
	c = addself(a);
	d = multiplicationself(b);
	e = d / c ;
	printf("%d\n", e);
	return 0;
}

