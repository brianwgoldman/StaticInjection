# StaticInjection

This repository provides an example of how to perform [Dependency Injection](https://en.wikipedia.org/wiki/Dependency_injection)
in C++11 that does not require any libraries. The only tools required are:

 * Macros
 * decltype
 * Preprocessor definitions

To see the example in action, use the following compilation commands:

 * `g++ -std=c++11 main.cpp` will compile using the real object.
 * `g++ -std=c++11 main.cpp -DTESTING` will compile using the fake.

## What is this good for?

The first big use case is testing. Lets say class A has a member instance of type B, B has C ... and X has Z.
In order to set up a test of A, you'll need to create instances of all those dependencies, and a bug in any
of them could cause your test to fail. What you would really like is to make a fake version of B that A
will use during testing, that is just smart enough to pass your tests if A performs correctly. Dependency
injection lets you do this by swapping out A's dependencies at will.

The second benefit comes in the code itself. If you need the default instance of A, normally you would
need to pass it in as an argument (from who knows where) or set up a factory of some kind. Same
for every step in A's dependency chain. Dependency injection simplifies that issue, as you can
now create A without passing it an instance of B as an argument: it just gets injected.

## What makes it extra cool?

Normally dependency injection requires defining interfaces and using polymorphism, or duck typed languages.
In this example, none of that is needed. Furthermore, all of the dependencies are set at compile time,
meaning there is no runtime overhead.

## How does it work?

TODO

