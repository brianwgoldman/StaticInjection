# Basic

To see this example in action, use the following two compile commands:

 * `g++ -std=c++11 main.cpp` - Compiles using `Foo.h`.
 * `g++ -std=c++11 main.cpp -DFOO_FAKE` - Compiles using `FooFake.h`

## Explanation

`main.cpp` wants to use `Injected` to display some information. However,
that is apparently too complicated to do with a single class, and so `Injected`
delegates that to `Foo`. Instead of constructing a `Foo` directly,
`Injected` uses `FooProvider.h` to get its instance. As the provider
could return any number of types that do what `Foo` does,
we let `decltype` determine that for us.

The result? `main.cpp` gets to use `Injected` without caring that `Injected`
depends on `Foo`. Furthermore, we can swap out `Foo` for `FooFake` in `Injected`
without modifying `Injected`. By executing the two different binaries, you can
see this in action, as `Foo` and `FooFake` display different strings.
