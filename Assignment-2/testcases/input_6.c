// testcase #6, testing all types of variable decalration 
int g;
int _g1, int _g2;
int int_arr[64];
int *int_ptr_arr[64];
int *int_ptr;

void null_var;
void _v1, void _v2;
void void_arr[64];
void *null_ptr_arr[64];
void *null_ptr;

float f1;
float f2, float f3;
float f_arr[64];
float *f_ptr_arr[64];
float *float_ptr;

int do_something(){
    g = 1;
    return g;
}

int main() {
    int m;
    do{
        if (!m){
            break;
        }
    }while(m);
    return 0;
}
