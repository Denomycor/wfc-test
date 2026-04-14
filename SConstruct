import os

env = Environment(
    CXX="g++",
    CPPPATH=["wfc-cpp/include"],
    LINKFLAGS=["-fsanitize=address"],
    CXXFLAGS=["-std=c++17", "-fsanitize=address", "-g"],
)

# env.Append(CXXFLAGS=[
#     "-O0",
#     "-fno-omit-frame-pointer"
# ])
#
# env.Append(LINKFLAGS=[
#     "-rdynamic"
# ])
#
# env.Append(LIBS=[
#     "boost_stacktrace_backtrace",
#     "dl"
# ])

# Enable compile_commands.json generation
env.Tool('compilation_db')

# Export env to submodule
wfc_lib = SConscript(
    os.path.join("wfc-cpp", "SConstruct"),
    exports="env",
)

# Build main executable
program = env.Program(
    target="app",
    source=["src/main.cpp"],
    LIBS=[wfc_lib],
    LIBPATH=["."]
)

# Generate compilation database
compdb = env.CompilationDatabase()

Default(program, compdb)

