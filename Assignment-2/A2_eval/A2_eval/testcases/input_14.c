// testcase #14, trying to use every production
int g;

int f(){
    return 0;
}

int i, int j;
void p; void *pt;
float f; float *fp;

int cumulative_sum(int len, int arr[]){
    int i;
    int sum;
    i = 0;
    sum = 0;

    while(i < (len-1)){
        while(1){
            sum = sum + (arr[i]); 
            // do something
            i = i + 1;
            if (i == len)
                break;

        }

    }
    return arr[len-1];
}

void fun(int a, void *vp, int ip[]){
    int loc_var;
    loc_var = cumulative_sum(a, ip);
    return;
}

int main() {
    {
        int i1;
        {
            int i2;
            i2 = 0;
            while(i2){
                i1 = i1 + 1;
                if (i1>100){
                    break;
                }
                else{
                    continue;
                }
            }
        }
    }
     switch(g){
    	case 1 :
    	break;
    	default :
    	 g = 0;
    }
    return;
}
