chicken_double_queue_lib = static_library('chicken-queue',
    files('package.c'),
    include_directories: inc_dir,
    gnu_symbol_visibility: 'hidden',
    install: true)

chicken_double_queue_dep = declare_dependency(
    link_with: chicken_double_queue_lib,
    include_directories: inc_dir)
