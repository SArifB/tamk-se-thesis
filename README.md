# TAMK Software Engineering Thesis

Title: Multilanguage and multiarchitecture monorepo managment and development  
Nimi: Monikielisen ja moniarkkitehtuurisen yhdistetyn koodivaraston hallinta ja kehitys

## Run Instructions

To run dev we need some system dependencies.
In this branch though we use nix flake though.
To continue, install nix package manager and enable experimental features.

```bash
# choose your shell
# this might take a while
nix develop --command bash

# optionally open dir in editor
nix develop --command bash -c "code ."
```

Build instructions:

```bash
# for cpp, only needed for cpp apps
cmake -B build/debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build/debug --target cpp-app1 cpp-app2 cpp-app3
ln -s debug/compile_commands.json build/

# for rust (optional)
cargo build
```

Run instructions:

```bash
# run cpp
./build/debug/projects/cpp-app1/cpp-app1
echo "hello" | ./build/debug/projects/cpp-app2/cpp-app2
./build/debug/projects/cpp-app3/cpp-app3

# run rust
cargo run --bin rust-app1

# run py
pushd projects/py-app2 && uv run main.py && popd

# run js and py apps for frontend on http://localhost:3000/
pnpm install --frozen-lockfile
pnpm run link-example-env
pnpm run -r --parallel dev
# since its parallel you might need to rerun above command
```

## Podman Compose

The three services needed for the frontend are containerized with Podman, and the
container images now use a NixOS/Nix base plus flake-defined runtime environments:

- `js-app1`: Vite frontend on `http://localhost:3000`
- `js-app2`: Hono API on `http://localhost:8000`
- `py-app1`: FastAPI service on `http://localhost:8100`

Run them with Podman Compose from the repo root:

```bash
pnpm run link-example-env
podman compose build
podman compose up
```

If you are on macOS and Podman is not running yet:

```bash
podman machine init
podman machine start
```
