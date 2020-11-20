typing.NewType

    for new psudo type which still works as a base type
    MyNewInt = typing.NewType('MyNewInt', int)

Callable
    to pass function/callback signature
    format callable[[args,..], returnType]

    def func(cb : callable[[int_arg1, int_arg2], floatRetType])
    use ... for first parameter of Callable to match any function params type list
    def func(cb : callable[..., floatRetType])
