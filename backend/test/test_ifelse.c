int main() {
    int a;
    int b;
    int c;
    a = 2;
    b = 1;
    if (a > 0) {
        if (b < 0) {
            c = 1;
        } else {
            c = 2;
        }
    } else {
        if (b < 0) {
            c = 3;
        } else {
            c = 4;
        }
    }
    return c;
}