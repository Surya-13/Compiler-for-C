// testcase #7, all function return types

int g;
void p;
float f;
int g1(){
    return 1;
}

int* g2(){
    /*int p;*/
    return &g;
}

void v1() {
    return;
}

void *v2() {
    return &p;
}

float f1() {
    return 1.0; 
}

float *f2() {
    return &f;
}

int main() {
    int m;
   switch(m * 2)
     {

     case 10:
     	printf("%d",m);
     case 9:
     	 m = 9;
         printf("%d",m);
         break;

     case 8:
         m = 8;
         printf("%d",m);
         break;

     case 7:
         m = 7;
         printf("%d",m);
         break;

     case 6:
         m = 6;
         printf("%d",m);
         break;

     case 5:
         m = 5;
         printf("%d",m);
         break;

     default:
         m = 1;
         printf("%d",m);
         break;

     }

    return 0;
}
