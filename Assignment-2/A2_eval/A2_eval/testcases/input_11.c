// testcase #11, testing complex expression everywhere

int i;
int *ip;
float f;
float *fp;
void v;
void *vp;


int main() {
    int m;
    int m1;
    int m2;
    int m3;
    m3 = 16;
    m2 = 4 * ( 2 * m3);
    m1 = 8 * ( 2 * ( m2 / 2));
    if(((m1 == (m2 * 8)) && (m3 == ((2 * (4/2)) * (18 % 8)))) || ((m1 <= (m2/2)) && (m3 >= (m3%3)))) {
        while(m){
            if (!m){
                m = do_something();
                break;
            }
        }

    }
     switch(m){
    	case 1 :
    	break;
    	default :
    	 m = 0;
    }
    return 0;
}
