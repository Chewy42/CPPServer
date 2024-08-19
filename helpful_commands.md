
# Helpful Commands

## Install Conan Dependencies into "/build" folder including missing dependencies

```bash
conan install . --output-folder=build --build=missing
```

## Build "/build" folder
```bash
cd build && cmake ..
```

## Build "/src" folder
Dont forget to add ALL src file names to add_executable in CMakeLists.txt 
```bash
cmake --build .
```

## Run the executable
```bash
./run
```
