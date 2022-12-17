//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//#include <complex.h>
//#define STACK_OVERFLOW -100
//#define STACK_UNDERFLOW -101
//#define MAX_SIZE_OF_STR 300
//#define MAX_SIZE_OF_VAR 20
//#define SIZE_OF_FUNCS_2 2 // размер массива указателей с двумя аргументами
//#define SIZE_OF_FUNCS_1 12 // размер массива указателей с одним аргументом
//#define SIZE_OF_OPER 5
//
//typedef enum type{
//    ADD, SUB, MULT, DIV, POW, BRACK, VAR, NUMB, FUNC2, FUNC1
//} TYPE;
//
//typedef struct leksema{
//    int type;
//    char name[10]; // название переменной
//    double complex cmp;
//} LEKSEMA;
//
//typedef struct node{ // это элемент списка, содержащий лексему
//    LEKSEMA val; // здесь лежит сама лексема
//    struct node* next; // здесь хранится указатель на следующий элемент списка
//} NODE;
//
//void Push(NODE **head, LEKSEMA val){// Функция добавления элемента в стек
//    NODE *tmp = NULL; // создаем указатель на новый элемент списка
//    tmp = (NODE*) malloc(sizeof(NODE)); // выделяем память для нового элемента списка
//    if(tmp == NULL) // проверяем выделилась ли память
//        exit(STACK_OVERFLOW);
//    tmp->next = *head; // теперь новый элемент списка будет хранить указатель на следующий элемент
//    tmp->val = val; // запишем в новый элемент значение
//    *head = tmp; // теперь указатель стека указывает на этот новый элемент (он стал "верхним")
//}
//
//void Pop(NODE **head) { // Процедура, удаляющая верхний элемент стека
//    NODE* tmp = NULL; // нам нужна временная переменная, чтобы не потерять адрес 1ого элемента, который нам нужно удалить
//    if (head == NULL) { // проверяем не пуст ли стек
//        exit(STACK_UNDERFLOW);
//    }
//    tmp = (*head); // заносим во временную переменную адрес 1ого элемента
//    (*head) = (*head)->next; // теперь head указывает на 2ой элемент, который теперь стал первым
//    free(tmp); // очищаем память
//}
//
//LEKSEMA* Top(NODE *head){// Функция возвращает указатель на верхний элемент стека
//    if(head == NULL) // если ничего в стеке нет, то вохвращаем NULL
//        return NULL;
//    return &(head->val); // возвращаем указатель на верхний элемент
//}
//
//int priority(char  operation){
//    switch(operation){
//        case '+':
//        case '-':
//            return 0;
//        case '*':
//        case '/':
//            return 1;
//        case '^':
//            return 2;
//        default: return -1;
//    }
//}
//
//double complex Abs(double complex x){
//    return cabs(x) + 0 * I;
//}
//
//double complex real(double complex x){
//    return creal(x) + 0 * I;
//}
//
//double complex imag(double complex x){
//    return cimag(x) + 0 * I;
//}
//
//double complex mag(double complex x){
//    return cabs(x) + 0 * I;
//}
//
//double complex phase(double complex x){
//    return carg(x) + 0 * I;
//}
//
//double complex LN(double complex x)
//{
//    return clog(x);
//}
//
//double complex Log(double complex x, double complex y){
//    return LN(y)/LN(x);
//}
//
//double complex Add(double complex x, double complex y){
//    return x + y;
//}
//
//double complex Sub(double complex x, double complex y){
//    return x - y;
//}
//
//double complex Mult(double complex x, double complex y){
//    return x * y;
//}
//
//double complex Div(double complex x, double complex y){
//    return x / y;
//}
//
//void Maths(LEKSEMA *var,const int *varSize, LEKSEMA *postfix, int sizeOfStr){
//    NODE *stack = NULL;
//    LEKSEMA x, tmp;
//    double complex (*funcs1[])(double complex) = {ccos, csin, ctan, clog, csqrt, Abs, cexp, real, imag,
//                                                  mag, phase};
//    double complex (*funcs2[])(double complex, double complex) = {cpow, Log};
//    double complex (*funcsOp[])(double complex, double complex) = {Add, Sub, Mult, Div, cpow};
//    char *nfuncs2[] = {"pow", "log"};
//    char *nfuncs1[] = {"cos", "sin", "tg", "ln", "sqrt", "abs", "exp", "real", "imag", "mag", "phase"};
////  в первом случае вызывается пов если нам так и написали, а во втором если написали ^
//    for(int i=0; i<sizeOfStr; ++i){
//        if(postfix[i].type == NUMB){
//            Push(&stack, postfix[i]);
//            continue;
//        }
//        if(postfix[i].type == VAR){
//            if(!strcmp(postfix[i].name, "PI")){
//                tmp.cmp = M_PI + 0 * I;
//                Push(&stack, tmp);
//                continue;
//            }
//            if(!strcmp(postfix[i].name, "e")){
//                tmp.cmp = M_E + 0 * I;
//                Push(&stack, tmp);
//                continue;
//            }
//            for(int j=0; j < *varSize; ++j){
//                if(!strcmp(postfix[i].name, var[j].name)){
//                    Push(&stack, var[j]);
//                    break;
//                }
//            }
//            continue;
//        }
//        if(postfix[i].type == FUNC1){
//            for(int j=0; j < SIZE_OF_FUNCS_1; ++j){
//                if (!strcmp(postfix[i].name, nfuncs1[j])){
//                    tmp.cmp = funcs1[j]((*Top(stack)).cmp);
//                    Pop(&stack);
//                    Push(&stack, tmp);
//                }
//            }
//            continue;
//        }
//        if(postfix[i].type == FUNC2){
//            for(int j=0; j < SIZE_OF_FUNCS_2; ++j){
//                if(!strcmp(postfix[i].name, nfuncs2[j])){
//                    x.cmp = (*Top(stack)).cmp;
//                    Pop(&stack);
//                    tmp.cmp = funcs2[j]((*Top(stack)).cmp, x.cmp);
//                    Pop(&stack);
//                    Push(&stack, tmp);
//                }
//            }
//            continue;
//        }
//        tmp = *Top(stack);
//        Pop(&stack);
//        x.cmp = funcsOp[postfix[i].type]((*Top(stack)).cmp, tmp.cmp);
//        Pop(&stack);
//        Push(&stack, x);
//    }
//    var[*varSize].cmp = (*Top(stack)).cmp;
//    Pop(&stack);
////посчитал и занёс значение в подаваемый номер ячейки в массиве переменных
//
////пробегает по массиву переменных и вызывает нужную функцию
//}
//
//void ItIsComma(char ** str, NODE ** stack, LEKSEMA *postfix, int *sizeOfStr){
//    while((*Top(*stack)).type != BRACK){
//        postfix[*sizeOfStr] = *Top(*stack);
//        (*sizeOfStr)++;
//        Pop(&*stack);
//    }
//    (*str)++;
//}
//
//void ItIsDigit(char ** str, LEKSEMA *postfix, int *sizeOfStr){
//    char tmp[10] = {'\0'};
//    int j = 0;
//    while(**str >= '0' && **str <= '9' || **str=='.' || **str=='j'){
//        tmp[j] = **str;
//        j++;
//        (*str)++;
//    }
//    tmp[j] = '\0';
//    if(tmp[strlen(tmp)-1] == 'j') {
//        tmp[strlen(tmp)-1] = '\0';
//        if(strlen(tmp) == 0)
//            postfix[*sizeOfStr].cmp = 0 + 1 * I;
//        else
//            postfix[*sizeOfStr].cmp = 0 + strtod(tmp, NULL) * I;
//        postfix[*sizeOfStr].type = NUMB;
//        (*sizeOfStr)++;
//    }
//    else{
//        postfix[*sizeOfStr].cmp = strtod(tmp, NULL) + 0 * I;
//        postfix[*sizeOfStr].type = NUMB;
//        (*sizeOfStr)++;
//    }
//}
//
//void ItIsFuncOrVar(char ** str, NODE ** stack, LEKSEMA * postfix, int * sizeOfStr){
//    char tmp[10] = {'\0'};
//    int j = 0;
//    LEKSEMA toStack;
//    while(**str >= 'a' && **str <= 'z' || **str >= 'A' && **str <= 'Z' || **str >= '0' && **str <= '9') {
//        tmp[j] = **str;
//        j++;
//        (*str)++;
//    }
//    tmp[j] = '\0';
//    if(**str == '('){
//        if (!strcmp("pow", tmp) || !strcmp("log", tmp) || !strcmp("^", tmp)){
//            toStack.type = FUNC2;
//        }
//        else
//            toStack.type = FUNC1;
//        strcpy(toStack.name, tmp);
//        Push(&*stack, toStack);
//        return;
//    }
//    strcpy(postfix[*sizeOfStr].name, tmp);
//    postfix[*sizeOfStr].type = VAR;
//    (*sizeOfStr)++;
//}
//
//void ItIsUnaryMinus(char ** str, LEKSEMA * postfix, int * sizeOfStr, int *flag, NODE ** stack){
//    LEKSEMA toStack;
//    char tmp[10] = {'\0'};
//    postfix[*sizeOfStr].type = NUMB;;
//    postfix[*sizeOfStr].cmp = 0 + 0 * I;
//    (*sizeOfStr)++;
//    (*flag) = 0;
//    tmp[0] = **str;
//    tmp[1] = '\0';
//    toStack.type = SUB;
//    strcpy(toStack.name, tmp);
//    Push(&*stack, toStack);
//    (*str)++;
//}
//
//void ItIsBinaryOperation(char ** str, NODE ** stack, LEKSEMA * postfix, int * sizeOfStr){
//    char tmp[10] = {'\0'};
//    LEKSEMA toStack;
//    int j;
//    char *operations[] = {"+", "-", "*", "/", "^"};
//    while (Top(*stack) != NULL && ((*Top(*stack)).type == FUNC1 || (*Top(*stack)).type == FUNC2 ||
//                                   priority((*Top(*stack)).name[0]) >= priority(**str))) {
//        postfix[*sizeOfStr] = *Top(*stack);
//        (*sizeOfStr)++;
//        Pop(&*stack);
//    }
//    tmp[0] = **str;
//    tmp[1] = '\0';
//    for(j=0; j < SIZE_OF_OPER; ++j) {
//        if (!strcmp(operations[j], tmp)) {
//            toStack.type = j;
//            break;
//        }
//    }
//    strcpy(toStack.name, tmp);
//    Push(&*stack, toStack);
//    (*str)++;
//}
//
//void ItIsBracket(char ** str, NODE ** stack, LEKSEMA * postfix, int * sizeOfStr){
//    char tmp[10] = {'\0'};
//    LEKSEMA toStack;
//    if(**str == '('){
//        tmp[0] = **str;
//        tmp[1] = '\0';
//        toStack.type = BRACK;
//        strcpy(toStack.name, tmp);
//        Push(&*stack, toStack);
//        (*str)++;
//    }
//    else if(**str == ')') {
//        while ((*Top(*stack)).type != BRACK) {
//            postfix[*sizeOfStr] = *Top(*stack);
//            (*sizeOfStr)++;
//            Pop(&*stack);
//        }
//        Pop(&*stack);
//        (*str)++;
//        if(Top(*stack) != NULL && ((*Top(*stack)).type == FUNC1 || (*Top(*stack)).type == FUNC2)){
//            postfix[*sizeOfStr] = *Top(*stack);
//            (*sizeOfStr)++;
//            Pop(&*stack);
//        }
//    }
//}
//
//void ReversePolishNotation(LEKSEMA *var, int *varSize, char * str){
//    NODE *stack = NULL;
//    LEKSEMA postfix[100];
//    int sizeOfStr = 0;
//    int flag = 0;
//    if(*str == '-')
//        flag = 1;
//    while(1){
//        if(*str=='\n' || *str == '\0') break;
//        if(*str == ' ') str++;
//        if(*str == ','){
//            ItIsComma(&str, &stack, postfix, &sizeOfStr);
//        }
//        if(*str >= '0' && *str <= '9' || *str=='.' || *str=='j' && !((*(str+1) >= 'a' && *(str+1) <= 'z')
//                                                                     || (*(str+1) >= 'A' && *(str+1) <= 'Z'))){
//            ItIsDigit(&str, postfix, &sizeOfStr);
//        }
//        if((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')){
//            ItIsFuncOrVar(&str, &stack, postfix, &sizeOfStr);
//        }
//        if(*str == '+' || *str == '-' || *str == '*' || *str == '/' || *str == '^') {
//            if(*str == '-' && (flag == 1 || *(str-1) == '(')){
//                ItIsUnaryMinus(&str, postfix, &sizeOfStr, &flag, &stack);
//                continue;
//            }
//            ItIsBinaryOperation(&str, &stack, postfix, &sizeOfStr);
//        }
//        if(*str == '(' || *str == ')'){
//            ItIsBracket(&str, &stack, postfix, &sizeOfStr);
//        }
//    }
//    while(Top(stack) != NULL){
//        postfix[sizeOfStr++] = *Top(stack);
//        Pop(&stack);
//    }
//    Maths(var, varSize, postfix, sizeOfStr);
//}
//
//void NewVar(LEKSEMA *var, int *varSize, char *str){
//    int i;
//    for(i = 0; *str!='=' && *str!=' '; str++, i++){
//        var[*varSize].name[i] = *str;
//    }
//    var[*varSize].name[i] = '\0';
//    char expression[MAX_SIZE_OF_STR] = {'\0'};
//    while(*str==' ' || *str=='=')
//        str++;
//    for(i = 0; *str!='\n' && *str!='\0'; i++, str++) {
//        expression[i] = *str;
//    }
//    ReversePolishNotation(var, varSize, expression);
//}
//
//void ReadingFile(LEKSEMA *var, int *varSize){
//    FILE* fr = fopen("input.txt", "rt");
//    char buf[10][MAX_SIZE_OF_STR];
//    int count=0;
//    while(fgets(buf[count], MAX_SIZE_OF_STR, fr)){
//        count++;
//    }
//    for(int i=count-1; i>=0; i--) {
//        if(i!=0) {
//            NewVar(var, varSize, buf[i]);
//            (*varSize)++;
//        }
//        else {
//            ReversePolishNotation(var, varSize, buf[i]);
//            (*varSize)++;
//        }
//    }
//    fclose(fr);
//}
//
//int main() {
//    FILE* fw = fopen("output.txt", "wt");
//    LEKSEMA var[MAX_SIZE_OF_VAR];
//    int varSize = 0;
//    ReadingFile(var, &varSize);
//    fprintf(fw, "Result: %.5f + %.5fi\n", creal(var[varSize-1].cmp), cimag(var[varSize-1].cmp));
//    fclose(fw);
//}
//результат хранится в последней ячейке переменных var


//#include "btree.h"
//#include <time.h>
//#include <stdlib.h>
//#include <stdio.h>
//
//int main()
//{
//    srand(time(0));
//    NODE* root=NULL;
//    for (int i=0;i<10;++i)
//    {
//        root= Add2Tree(root,rand()%21-10);
//    }
//    simmetric(root);
//    printf("\n");
////    pre(root);
////    printf("\n");
////    post(root);
////    printf("\n");
//    PrintTreeOnSide(root,0);
//    printf("\n");
//    int n;
//    scanf("%d",&n);
//    root=DeleteFromTree(root,n);
//    simmetric(root);
//    printf("\n");
//    PrintTreeOnSide(root,0);
//    printf("\n");
//    root=DeleteTree(root);
//    return 0;
//}

//#include "queue.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <time.h>
//
//extern STATE state;
//char* state_str[]={"NORMAL","OVERFLOW","UNDERFLOW", "EMPTY"};
//
//int main()
//{
//    srand(time(0));
//    int n=top();
//    if (state==NORMAL)
//        printf("%5d",n);
//    else
//        printf("%s\n",state_str[state]);
//    pop_front();
//    if (state==NORMAL)
//        printf("OK\n",n);
//    else
//        printf("%s\n",state_str[state]);
//    for (int i=0;i<15;++i)
//    {
//        push_back(rand()%21-10);
//    }
//    int count=5;
//    while (!is_empty() && count--)
//    {
//        printf("%5d",top());
//        pop_front();
//    }
//    n=top();
//    if (state==NORMAL)
//        printf("\n%5d\n",n);
//    else
//        printf("%s\n",state_str[state]);
//    pop_front();
//    if (state==NORMAL)
//        printf("OK\n",n);
//    else
//        printf("%s\n",state_str[state]);
//    return 0;
//}

#include <stdio.h>

//typedef union temp
//{
//    char c;
//    double a;
//    int b;
//}TEMP;
//
//typedef struct str
//{
//    char c;
//    double a;
//    int b;
//}STR;
//
//int main()
//{
//    STR temp;
//    printf("%d\n",sizeof(TEMP));
//    printf("%d\n",sizeof(STR));
//    printf("%x\n%x\n%x\n",&temp.c,&temp.a,&temp.b);
//}

