


int addition(int a, int b)
{
    return a + b;
}


int subtraction(int a, int b)
{
    return a - b;
}

int operation(int x, int y, int(*functocall)(int, int))
{
    int g;
    g = (*functocall)(x, y);
    return g;
}