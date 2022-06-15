src += files([
	'argp-ba.c',
	'argp-eexst.c',
	'argp-fmtstream.c',
	'argp-help.c',
	'argp-parse.c',
	'argp-pv.c',
	'argp-pvh.c',
	'argp-xinl.c',
	'argp-fs-xinl.c',
])

incdir += include_directories('.')

# Install glibc's argp.h to <argp-standalone/argp.h> so we can put our own
# argp.h between the user and the copypasted glibc header.
install_headers('argp.h', subdir : 'argp-standalone')
