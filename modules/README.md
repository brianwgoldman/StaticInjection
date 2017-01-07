# Modules

In this example we explore two new features of injection: Modules and Testing.
As before, each requires their own build:

 * `g++ -std=c++11 main.cpp` - Compiles using the real version of everything
 * `g++ -std=c++11 InjectedTest.cpp` - Real `Injected` but fake everything else
 * `g++ -std=c++11 FooTest.cpp` - Real `Foo` but fake everything else
 * `g++ -std=c++11 BarTest.cpp` - Real `Bar` but fake everything else

# Explanation

In this example we have a deeper dependency chain: `main.cpp` needs `Injected`, which needs
`Foo`, which needs `Bar`. In order to avoid having a `-D` statement for every injectable thing,
we now use a `Module`. `Module`'s define how all of the `Provider`s should act by default.
In this case `main.cpp` loads `Module.h`, which specifies that we are going to use the real
version of everything. If we have a different executable (like tests) we can create a different
module that defines a different set of macros. NOTE: `Module`s need to be included before
`Provider`s. See the best practices section of the top level README for more details.

All but the first compile command create test executables. These all include `ModuleFake.h`,
which defines that we are using the `Fake` version of `Foo` and `Bar`.
In doing so, we can test each individual type using a version of its dependencies that
have well defined behavior. For instance, if there is a bug in `Bar`, our tests
of `Injected` and `Foo` won't be effected.

