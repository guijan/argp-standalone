incdir += include_directories('.', is_system : true)

# Install glibc's argp.h to <argp-standalone/argp.h> so we can put our own
# argp.h between the user and the copypasted glibc header.
#
# Use Meson 0.63's preserve_path when 0.63 is widely adopted.
install_headers('argp-standalone/argp.h', subdir : 'argp-standalone')
