// testcase #12, testing array operations

int g;

int int_a;
int int_arr[10];
int int_ptr_arr[10];


int do_something(){
    g = 1;
    return g;
}

int main() {
    int m;
    int_a = 1;
    m = 1;
    while(m < 10) {
        int_arr[m] = int_a + m;  
        int_ptr_arr[m] = &(int_arr[m]); 
    }
     switch(m){
    	case 1 :
    	break;
    	default :
    	 m = 0;
    }

    return 42;
}
