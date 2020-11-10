int i;
float* arr[20], int b;
int x, int y, int z;

void f1(){
    i = 0;
}

int* f2(){
    return &i;
}

float* f3(){
    return arr[i];
}

void main(){
    y = 1;
    x = y;
    z = x;
    y--;
    x++;
}
