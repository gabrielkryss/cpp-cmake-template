#include "engine.h"

import std;
import MyModule;

int main() {
    MyClass myClass1;
    myClass1.sayHello();

    /*MY_ENGINE::MyClass myClass2;*/
    /*myClass2.sayHello();*/

    /*Foo foo;*/
    /*foo.sayHello();*/

    std::print("Hello, EngineApp!\n");

    MY_ENGINE::Engine engine;

    engine.initialize();
    engine.run();
    engine.stop();

    if (!engine.isRunning()) {
        std::print("Engine has stopped running.\n");
    }

    return 0;
}
