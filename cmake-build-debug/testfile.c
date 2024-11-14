int a[6] = {1, 2, 3, 4, 5, 6};
int foo(int y[]) {
    return y[2];
}

int main() {
    foo(a);
    return 0;
}