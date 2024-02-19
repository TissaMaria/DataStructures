int scoreOfParentheses(char* s) {
    int stack[50]; 
    int top = -1;
    int score = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            top++;
            stack[top] = 0;
        } else{
            if (stack[top] == 0) {
                stack[top] = 1;
            } else {
                int innerScore = 0;
                while (stack[top] != 0) {
                    innerScore += stack[top];
                    top--; 
                }
                stack[top] = 2 * innerScore; 
            }
        }
    }

    while (top != -1) {
        score += stack[top];
        top--; 
    }

    return score;
}