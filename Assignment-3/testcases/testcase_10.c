int main() {

	int number1;
	int temp;
	number1=2345;
	while(number1){
		temp = number1 % 10;
		number1 = number1 / 2;
		printf("%d\n",temp);
	}


	return 0;
}
