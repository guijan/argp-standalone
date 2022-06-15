project('argp-standalone', 'c',
        default_options: ['c_std=gnu99', 'b_lto=true', 'warning_level=2'])

cc = meson.get_compiler('c')
src = []
# Only the include directories used to compile the library go here.
incdir = [include_directories('.')]

# All the trickery to make argp compile unmodified goes here.
subdir('compat')
# Unmodified argp.h header from glibc/argp/argp.h
subdir('include')
# Unmodified argp sources from glibc/argp/argp-*.{c,h}
subdir('src')

conf_data = configuration_data()

if host_machine.system() != 'windows'
	soversion = '0'
	libversion = '0.0.0'
endif

conf_data.set10('HAVE_CONFIG_H', true)
conf_data.set10('HAVE_ALLOCA_H', cc.check_header('alloca.h'))

conf_data.set('HAVE_UNISTD_H', cc.check_header('unistd.h'))
conf_data.set('HAVE_LIBINTL_H', cc.check_header('libintl.h'))

conf_data.set10('HAVE_ASPRINTF',
                cc.has_function('asprintf', prefix: '#include <stdio.h>'))
conf_data.set10('HAVE_MEMPCPY',
                cc.has_function('mempcpy', prefix: '#include <string.h>'))
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

deps = []
if cc.check_header('libintl.h')
	deps += dependency('intl')
endif

configure_file(input : 'meson_config.h.in',
               output : 'config.h',
               configuration : conf_data)

add_project_arguments('-DHAVE_CONFIG_H=1', language : 'c')

if host_machine.system() != 'windows'
  argp_library = library('argp',
		         src,
		         soversion : soversion,
		         version : libversion,
                         include_directories : incdir,
		         dependencies : deps,
		         install : true)
else
  argp_library = static_library('argp',
                                src,
                                include_directories : incdir,
                                dependencies : deps,
                                install : true)
endif

argp_dep = declare_dependency(link_with : argp_library,
                              # Users only need our compatibility header and the
                              # unmodified glibc header.
	                      include_directories : ['compat/hdr', 'include'])

if meson.version().version_compare('>= 0.54.0')
	meson.override_dependency('argp-standalone', argp_dep)
endif

import('pkgconfig').generate(argp_library, filebase : 'libargp')

subdir('test')
