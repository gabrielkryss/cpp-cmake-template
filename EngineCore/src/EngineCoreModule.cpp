module EngineCoreModule;

import std;

Foo::Foo() {}

void Foo::sayHello() {
  std::print("Hello from EngineCore::Foo!\n");
}

namespace MY_ENGINE {

MyClass::MyClass() {}

void MyClass::sayHello() {
  std::print("Hello from EngineCore::MY_ENGINE::MyClass!\n");
}

} // namespace MY_ENGINE

