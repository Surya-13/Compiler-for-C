int main() {
	int variable1;
	int variable2;
	variable2=-10;
	variable1 = 6;
	while (variable1 >= 1) {
		int c;
		c = variable1;
		printf("%d\n", variable1);
		variable1 = c - 1;
	}
	while(variable2 < 0){
		printf("%d\n",variable2);
		variable2= variable2 + 1;
	}
}
