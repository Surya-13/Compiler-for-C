int main() {
	int a;
	int b;
	int c;
	int e;
	int temp;
	a = 54;
	b = 64;
	temp=6;
	c = (a <= b);
	c = !(c);
	e = !c;
	if (c) {
		int d;
		d = a * 3;
		printf("%d\n", d);
	}
	else {
		int f;
		f = b / 3;
		printf("%d\n", f);	
	}
	while(temp > 0){
		temp= temp - 1;
		printf("%d\n",temp);
	}
	return 0;
}
