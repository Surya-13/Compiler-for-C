// testcase #9, nested compound statements

int g;
void p;
float f;

int hello_w(int i){
    int level;
    {
        int level1;
        level1 = 1;
        level = level1;
        {
            int level2;
            level2 = level1 + 1;
            level = level2;
            {
                int level3;
                level3 = level2 + 1;
                level = level3;
                while(level < 10){
                    level = level + 1;
                    if (level == 10){
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    {
        {
            {
                {
                    int i1;
                    i1 = hello_w();
                    return (1-1);
                }
            }
        }
    }
}
