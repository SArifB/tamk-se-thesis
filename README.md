# TAMK Software Engineering Thesis

Title: Multilanguage and multiarchitecture monorepo managment and development  
Nimi: Monikielisen ja moniarkkitehtuurisen yhdistetyn koodivaraston hallinta ja kehitys

## Run Instructions

To run dev we need some system dependencies:

```bash
# for mac we can use homebrew
brew install cmake ninja llvm
```

Build instructions:

```bash
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target cpp-app1 cpp-app2
```

Run instructions:

```bash
./build/projects/cpp-app1/cpp-app1
echo "hello" | ./build/projects/cpp-app2/cpp-app2
```
