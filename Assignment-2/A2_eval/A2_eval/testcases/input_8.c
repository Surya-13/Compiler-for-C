// testcase #8, different function params

/*int fi1(int i1){*/
    /*return 1;*/
/*}*/

/*int* fip1(int *p1){*/
    /*return &g;*/
/*}*/
int g;
void p;
float f;
int g1(int i){
    return 1;
}

int* g2(int *i){
    /*int p;*/
    return &g;
}

void v1() {
    return;
}

void *v2(void *v) {
    return &p;
}

float f1(float f) {
    return 1.0; 
}

float *f2(float *f) {
    return &f;
}

int do_something(int i, int *i2, float f, float j[]){
    g = 1;
    g = g + 1;
    return g;
}

int main() {
    int m;
    while(m){
        if (!m){
            /*do_something();*/
            break;
        }
    }

    return 0;
}

int wrap_main(int argc, int* argv[]) {

    return (1-1);
}
