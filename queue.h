//
// Created by liza on 27.02.2022.
//

#ifndef CALCULATOR_QUEUE_H
#define CALCULATOR_QUEUE_H

typedef struct Node
{
    int value;
    struct Node *next;
}NODE;

typedef enum State {NORMAL,OVERFLOW,UNDERFLOW, EMPTY} STATE;

void push_back(int value);
void pop_front();
int is_empty();
int top();

#endif //CALCULATOR_QUEUE_H
