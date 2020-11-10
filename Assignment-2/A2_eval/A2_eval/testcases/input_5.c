// testcase #5, complex while loops

int g;

void f() {
    g = 0;
}

int rand() {
    int rand_var;
    rand_var = 0;    
    if (rand_var) {
        return -1;
    }
    else{
        return 1;
    }
}

void main() {
    int i1;
    i1 = 5;
    while(i1 < 10){
        while(i1 > 1){
            while( i != 7){
               i1 = i1 + (rand());
               break;
            }
            break;
        }
        break;
    }
    while((1 + 1) == (3 - 1)){
        while(1){
            while(1){
                while(1){
                    break;
                }
            }
        }
    }
    while(1){
        while(1){
            while(1){
                while(1){
                    while(1)
                       continue; 
                }
            }
        }
    }
    return;
}
