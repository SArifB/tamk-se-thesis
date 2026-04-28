# TAMK Software Engineering Thesis

Title: Multilanguage and multiarchitecture monorepo managment and development  
Nimi: Monikielisen ja moniarkkitehtuurisen yhdistetyn koodivaraston hallinta ja kehitys

## Run Instructions

To run dev we need some system dependencies:

```bash
# for mac we can use homebrew
brew install cmake ninja llvm emscripten rust wasm-pack node pnpm uv
```

Build instructions:

```bash
# for cpp, only needed for cpp apps
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target cpp-app1 cpp-app2 cpp-app3

# for rust (optional)
cargo build
```

Run instructions:

```bash
# run cpp
./build/projects/cpp-app1/cpp-app1
echo "hello" | ./build/projects/cpp-app2/cpp-app2
./build/projects/cpp-app3/cpp-app3

# run rust
cargo run --bin rust-app1

# run py
pushd ./projects/py-app2 && uv run main.py && popd

# run js and py apps for frontend on http://localhost:3000/
pnpm install
pnpm run link-example-env
pnpm run -r --parallel dev
```
