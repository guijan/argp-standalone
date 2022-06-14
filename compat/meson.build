incdir += include_directories('.')
subdir('getopt')

string_funcs = ['mempcpy', 'strcasecmp', 'strchrnul', 'strndup']

foreach func : string_funcs
  if not cc.has_function(func, prefix : '#include <string.h>')
    src += files(func + '.c')
  endif
endforeach
