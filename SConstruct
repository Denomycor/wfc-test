import os

env = Environment(
    CXX="g++",
    CXXFLAGS=["-std=c++17", "-O2"],
)

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

Default(program)

