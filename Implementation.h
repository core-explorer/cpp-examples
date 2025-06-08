#pragma once
#include "Interface.h"
#include <cstdio>

class Implementation :public Interface{
    public: 
        virtual ~Implementation(){}
        void doSomething() override {
    printf("doSomething() in Implementation!\n");
}

// Derived classes can add extra functionality
virtual void doSomeMore() {
    printf(" doSomethingMore() in Implementation!\n");
}
};