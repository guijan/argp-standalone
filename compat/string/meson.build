incdir += include_directories('.')

foreach func : ['mempcpy', 'strcasecmp', 'strchrnul', 'strndup']
  if not cc.has_function(func, prefix : '#include <string.h>')
    src += files(func + '.c')
  endif
endforeach
