incdir += include_directories('.')

foreach func : ['mempcpy', 'strchrnul', 'strndup']
  if not cc.has_function(func, prefix : '#include <string.h>')
    src += files(func + '.c')
  endif
endforeach

if not cc.has_function('strcasecmp', prefix : '#include <strings.h>')
  if cc.has_function('_stricmp', prefix : '#include <string.h>')
    src += files('strcasecmp.c')
  else
    error('no way to implement strcasecmp') # Won't happen.
  endif
endif
