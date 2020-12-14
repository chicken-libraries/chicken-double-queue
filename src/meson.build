chicken_lib = static_library('chicken',
    files('package.c'),
    include_directories: inc_dir,
    gnu_symbol_visibility: 'hidden',
    install: true)

chicken_dep = declare_dependency(
    link_with: chicken_lib,
    include_directories: inc_dir)
