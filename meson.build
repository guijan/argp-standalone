project('argp-standalone', 'c',
        default_options: ['c_std=gnu99', 'b_lto=true', 'warning_level=2'])

cc = meson.get_compiler('c')
src = []
# Only the include directories used to compile the library go here.
incdir = [include_directories('.')]

# All the trickery to make argp compile unmodified goes here.
subdir('compat')
# Minimally modified argp.h header from glibc/argp/argp.h
subdir('include')
# Minimally modified argp sources from glibc/argp/argp-*.{c,h}
subdir('src')

if host_machine.system() != 'windows'
	soversion = '0'
	libversion = '0.0.0'
endif

deps = []

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
