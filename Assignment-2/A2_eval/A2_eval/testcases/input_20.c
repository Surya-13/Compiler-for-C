int i;

void main(){
   if(1) {
    if (1) {
        if (1) 
            i = 1;
        else
            i = 0;
    }
   } 
}

void foo() {
    if (1){
        i = 1;
        i = 0;
        i = 2;
        i = i + 1;
        i = 10;
    }
}
