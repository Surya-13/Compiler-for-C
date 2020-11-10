int main() {
	int first;
	int second;
	int temp;
	int count;
	count= 16;
	first =1;
	second =2;
	while(count > 0){
		temp=first + second;
		first = second;
		second = temp;
		count= count -1;
	}
	printf("%d\n", temp);
	return 0;
}
