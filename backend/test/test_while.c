int main() {
    int a;
    int b;
    a = 4;
    while (a > 0) {
        if ( a == 2) {
            b = 10;
            break;
        }
        a = a - 1;
    }

    while (a > 1) {
        if (b == 10) {
            b = b + 10;
            continue;
        }
        b = b - 1;
        a = a - 1;
    }

    return b;
}