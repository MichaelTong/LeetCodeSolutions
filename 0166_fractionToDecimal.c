/*
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 *
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 *
 * Example 1:
 * Input: numerator = 1, denominator = 2
 * Output: "0.5"
 *
 * Example 2:
 * Input: numerator = 2, denominator = 1
 * Output: "2"
 *
 * Example 3:
 * Input: numerator = 2, denominator = 3
 * Output: "0.(6)"
 */

char *division(long r, long de) {
    long initialR = r, repeatedR = 0;
    long bits = 0, i= 0, repeated = 0;
    long startRepeat = 0;
    char *rarray = (char *)calloc(de, sizeof(char));
    char *ret;
    do {
        if (rarray[r] == 1) break;
        rarray[r] = 1;
        r *= 10;
        r %= de;
        bits++;
    } while (r != 0);
    if (r != 0) repeated = 2;
    repeatedR = r;
    r = initialR;
    ret = (char *)malloc((bits+repeated+1)*sizeof(char));
    i = 0;
    while (1) {
        char toput;
        r *= 10;
        toput = '0' + r/de;
        if (r/10 == repeatedR) {
            if (startRepeat != 1){
                startRepeat = 1;
                ret[i] = '(';
                i ++;
            } else {
                ret[i] = ')';
                i++;
                break;
            }
        }
        ret[i] = toput;
        i++;
        r %= de;
        if (r == 0) break;
    }
    ret[i] = 0;
    return ret;
}

char *itoa(long num, long sign) {
    long x = num;
    long bits = 0;
    long i, len = sign == -1? 1:0;
    char * ret;
    do {
        x /= 10;
        bits ++;
    } while(x);
    len += bits + 1;
    ret = (char*)malloc(len*sizeof(char));
    x = num;
    for (i = 0; i < bits; i++) {
        ret[len - i - 2] = x%10 + '0';
        x /= 10;
    }
    ret[len - 1] = 0;
    if (sign == -1) ret[0] = '-';
    return ret;
}

char * fractionToDecimal(int numerator, int denominator){
    long div, r;
    long sign = numerator >= 0?1:-1, sigd = denominator>=0?1:-1;
    long lnumerator = numerator * sign;
    long ldenominator = denominator * sigd;
    sign = sign * sigd;
    div = lnumerator/ldenominator;
    r = lnumerator%ldenominator;
    if (numerator == 0) sign = 1;
    char *strdiv = itoa(div, sign);
    if (r == 0) return strdiv;
    else {
        char *strr = division(r, ldenominator);
        char *ret = (char*)malloc((strlen(strdiv) + strlen(strr) + 2)*sizeof(char));
        sprintf(ret, "%s.%s", strdiv, strr);
        return ret;
    }
}