#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

size_t convertValue(char c) {
    switch (c) {
        case 'I': return I;
        case 'V': return V;
        case 'X': return X;
        case 'L': return L;
        case 'C': return C;
        case 'D': return D;
        case 'M': return M;
    }

    return 0;
}

int romanToInt(char* s) {
    int total = 0;
    size_t len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (i < len - 1 && convertValue(s[i]) < convertValue(s[i+1])) {
            total -= convertValue(s[i]);
        } else {
            total += convertValue(s[i]);
        }
    }

    return (total);
}