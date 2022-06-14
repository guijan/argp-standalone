incdir += include_directories('.')

conf_data = configuration_data()

conf_data.set10('HAVE_CONFIG_H', true)
conf_data.set10('HAVE_ALLOCA_H', cc.check_header('alloca.h'))

conf_data.set('HAVE_UNISTD_H', cc.check_header('unistd.h'))
conf_data.set('HAVE_LIBINTL_H', cc.check_header('libintl.h'))

conf_data.set10('HAVE_ASPRINTF',
                cc.has_function('asprintf', prefix: '#include <stdio.h>'))
conf_data.set10('HAVE_MEMPCPY',
                cc.has_function('mempcpy', prefix: '#include <string.h>'))
# strcasecmp() is defined to be in <strings.h> (not <string.h>) by POSIX but
# argp wants it in <string.h>. HAVE_STRCASECMP is only used to check whether we
# should add a declaration.
conf_data.set10('HAVE_STRCASECMP',
                cc.has_function('strcasecmp', prefix: '#include <string.h>'))
conf_data.set10('HAVE_STRCHRNUL',
                cc.has_function('strchrnul', prefix: '#include <string.h>'))
conf_data.set10('HAVE_STRNDUP',
                cc.has_function('strndup', prefix: '#include <string.h>'))

conf_data.set10('HAVE_DECL_FLOCKFILE', cc.has_function('flockfile'))
conf_data.set10('HAVE_DECL_FPUTS_UNLOCKED',
                cc.has_function('fputs_unlocked',
                                prefix : '#include <stdio.h>'))
conf_data.set10('HAVE_DECL_FPUTC_UNLOCKED',
                cc.has_function('fputc_unlocked',
                                prefix : '#include <stdio.h>'))
conf_data.set10('HAVE_DECL_FWRITE_UNLOCKED',
                cc.has_function('fwrite_unlocked',
                                prefix : '#include <stdio.h>'))
conf_data.set10('HAVE_DECL_PUTC_UNLOCKED',
                cc.has_function('putc_unlocked', prefix : '#include <stdio.h>'))

conf_data.set10('HAVE_DECL_PROGRAM_INVOCATION_NAME',
                cc.has_function('program_invocation_name',
                                prefix : '#include <errno.h>'))
conf_data.set10('HAVE_DECL_PROGRAM_INVOCATION_SHORT_NAME',
                cc.has_function('program_invocation_short_name',
                                prefix : '#include <errno.h>'))

configure_file(input : 'config.h.in',
               output : 'config.h',
               configuration : conf_data)
