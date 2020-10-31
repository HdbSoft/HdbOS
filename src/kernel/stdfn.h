#ifndef GINGER_STDFNS_H
#define GINGER_STDFNS_H

#define len(arr) \
    sizeof(arr) / sizeof(arr[0])

Ui32 strlen(const String str) {
    Ui32 length = 0;
    while (str[length])
        length++;
    return length;
}

Ui32 digits(int num) {
    Ui32 count = 0;
    if (num == 0)
        return 1;

    while (num > 0) {
        count++;
        num = num / 10;
    }
    return count;
}

void ItoA(int num, String number) {
    int dgcount = digits(num);
    int index = dgcount - 1;
    char x;
    if (num == 0 && dgcount == 1) {
        number[0] = '0';
        number[1] = '\0';
    }
    else {
        while (num != 0) {
            x = num % 10;
            number[index] = x + '0';
            index--;
            num = num / 10;
        }
        number[dgcount] = '\0';
    }
}

#endif
//ginger standard functions