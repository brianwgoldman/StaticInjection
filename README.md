# StaticInjection

This repository provides examples of how to perform [Dependency Injection](https://en.wikipedia.org/wiki/Dependency_injection)
in C++11 that does not require any libraries. The only tools required are:

 * Macros
 * decltype
 * Preprocessor definitions

Examples:

 * `basic/` - The simplest version
 * `module/` - Handle injection via modules, useful for large projects

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

Finally, this version of injection is helpful if you want to change the dependencies of a class.
If you create A in a thousand places, but then realize that A needs an additional dependency, you
would normally need to modify everywhere A is created. The way injection is performed in these examples,
you can avoid all that and just change the definition of A.

## What makes it extra cool?

Normally dependency injection requires defining interfaces and using polymorphism, or duck typed languages.
In this example, none of that is needed. Furthermore, all of the dependencies are set at compile time,
meaning there is no runtime overhead.

## How does it work?

For more detailed description, see the example subfolders. However, at a high level
here are the basic steps

1. Instead of including your dependency's header directly, include a `Provider` header instead.
2. The `Provider` knows about every class that can be used to satisfy that dependency.
3. Which class the provider returns is controlled via macro definitions.
4. Instead of specifying the type of your dependency, detect it by applying `decltype` to the `Provider` defined injector.

So in order to create a new class that satisfies a dependency, you just have to modify the `Provider`, not everywhere its used.
In order to switch between classes, you just have to change which macros are defined.

## Best Practices

Since this isn't a library, just a way of using existing language tools, it seems appropriate to provide advice
on how to keep everything maintainable.

 * Even though you can, never name two types identically.
 * Macros that control which injector to use should do nothing but be defined / undefined
 * Macros that perform injection should include INJECT in their name
 * All types created specifically for test purposes should be named some combination of Fake or Mock and the name of the type it is faking.
 * Providers should have Provider in their filename.
 * Providers should fail to compile if you don't specify which version it should use.
 * Always prefer modules to compiler flags.
 * Modules should only be included in `main`, test files, and other modules.
 * Modules should be included before any other non-STL includes.
 * As always, keep your naming conventions internally consistent.
