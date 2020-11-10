// testcase #10, all expressions

int g;
int p;
int f;
int *pt;
struct StudentData{
    int stuid;
    int stuage;
};

int test_expr(int a) {
    int e1;
    int e2; 
    int e3;
     struct StudentData *student;
    e1 = 1;
    e2 = 2;
    e3 = e1;
     student->stuid = 1234;
     student->stuage = 30;
    if (e1 == e2) {
        return 1;
    }
    if ((e1 == e2) || (e1 == e3)) {
        return 2;
    }
    if (e1 != e2) {
       return 3;  
    }

    if (e1 < e2) {
        return 4;
    }
    if (e1 > e2) {
        return 5;
    }
    if (e1 >= e2) {
        return 6;
    }
    if (e1 <= e2){
        return 7;
    }
    if ((e1 == e2) && ( e1 >= e3)){
        return 8;
    }
    if ((e1 + e2) > 0) {
        return 9;
    } 
    if ((e1 - e2) < 0) {
        return 10;
    }
    if ((e1 * e2) == 2) {
        return 11;
    }
    if ((e2/e1) == 2) {
        return 12;
    }
    if ((e3 % e1) == 0){
        return 13;
    }
    if (!(e3 == e1)){
        return 14;
    }
    if(e1 <=> e2 )
    	return 12;
     if((sizeof(student)) > 0)
    	return 16;
    if (1) {
        e3 = -e1;
    } else if (1) {
        e3 = +e1;
    } else if (1){
       pt = &p; 
    } else{
        p = *pt; 
    }
    
    return 0;

}

int main() {
    return 0;
}
