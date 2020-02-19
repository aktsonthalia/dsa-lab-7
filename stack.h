typedef struct Node * Node;
typedef struct Stack * Stack;

Stack createStack();
void push(Stack s, int n);
int pop(Stack s);
void printStack(Stack s);
int isEmpty(Stack s);