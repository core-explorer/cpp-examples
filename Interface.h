#pragma once

class Interface {
    public: 
        virtual ~Interface() {}
        virtual void doSomething() = 0;
};