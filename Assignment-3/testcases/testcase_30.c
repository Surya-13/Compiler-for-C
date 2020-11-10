int Dhoni () {
	int numberFive;
	numberFive = 7;
	printf("%d\n", numberFive);
	return 0;
}

int Kohli () {
	int numberFour;
	int other;
	other = Dhoni();
	numberFour = 18;
	printf("%d\n", numberFour);
	return 0;
}

int Dhavan () {
	int numberThree;
	int other;
	other = Kohli();
	numberThree = 25;
	printf("%d\n", numberThree);
	return 0;
}

int Sehwag () {
	int numberTwo;
	int other;
	other = Dhavan();
	numberTwo = 44;
	printf("%d\n", numberTwo);
	return 0;
}

int Sachin () {
	int numberOne;
	int other;
	other = Sehwag();
	numberOne = 10;
	printf("%d\n", numberOne);
	return 0;
}


int main() {
	int jerseynumber;
	jerseynumber = Sachin();
	return 0;
}

