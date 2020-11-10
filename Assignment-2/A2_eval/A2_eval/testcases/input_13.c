// testcase #13, simple palindrome check

int main()
{
    int n;
    int revInt;
    int remainder;
    int origInt;
    int ans;
    int count;
    // get input
    origInt = 12321;
    revInt = 0;
    count = 0;
    while (n != 0){
        remainder = n%10;
        revInt = (revInt * 10) + remainder;
        n = ((((n / 10))));
        count++;
    }
    if (origInt == revInt)
        ans = (1+(0-0));
    else{
        ans = (0+(1-1));
    }
     switch(n){
    	case 1 :
    	break;
    	default :
    	 n = 0;
    }
    return 0;
}
