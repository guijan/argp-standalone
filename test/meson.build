test('ex1', executable('ex1', 'ex1.c', dependencies : [argp_dep]))

ex3 = executable('ex3', 'ex3.c', dependencies : [argp_dep])
test('ex3', ex3, args : ['-o', 'A', 'B', 'C'])

ex4 = executable('ex4', 'ex4.c', dependencies : [argp_dep])
test('ex4', ex4, args : ['-vso', 'A', 'B', 'C', 'D E', 'F G', 'H', ''])
