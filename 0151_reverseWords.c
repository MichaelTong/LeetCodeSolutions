/*
 * Given an input string, reverse the string word by word.
 * Example 1:
 *
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * Example 2:
 *
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing spaces.
 * Example 3:
 *
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a single
 * space in the reversed string.
 *
 * Note:
 *
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in the
 * reversed string.
 *
 * Follow up:
 * For C programmers, try to solve it in-place in O(1) extra space.
 */

char *findWordStart(char *s) {
    char *p = s;
    while(*p == ' ') p++;
    return p;
}

char *findWordEnd(char *s) {
    char *p = s;
    while(*p != ' ' && *p != '\0') p++;
    return p;
}

void reverseWord(char *head, char *tail) {
    char tmp;
    while (head < tail-1) {
        tmp = *head;
        *head = *(tail - 1);
        *(tail - 1) = tmp;
        head++;
        tail--;
    }
}

void strip(char *s) {
    char *p = s;
    int start = 1, pendingSpace = 0;
    while (*p != 0) {
        if (*p == ' ' && start == 0) {
            pendingSpace = 1;
        } else if (*p != ' ') {
            if (start != 1) {
                if (pendingSpace) {
                    *s = ' ';
                    s ++;
                    pendingSpace = 0;
                }
            }
            start = 0;
            *s = *p;
            s++;
        }
        p++;
    }
    *s = 0;
}

char * reverseWords(char * s){
    char *head, *tail, *p;
    strip(s);
    p = s;
    tail = s;
    while (*tail != '\0') {
        head = findWordStart(tail);
        tail = findWordEnd(head);
        reverseWord(head, tail);
    }
    reverseWord(s, tail);
    return s;
}