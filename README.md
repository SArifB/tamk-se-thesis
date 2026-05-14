# TAMK Software Engineering Thesis

Title: Multilanguage and multiarchitecture monorepo managment and development  
Nimi: Monikielisen ja moniarkkitehtuurisen yhdistetyn koodivaraston hallinta ja kehitys

## Run Instructions

To run dev we need some system dependencies:

```bash
# for mac we can use homebrew
brew install node pnpm uv cmake ninja llvm
```

Run instructions:

```bash
# run js
pnpm install --frozen-lockfile
pnpm run --recursive --parallel dev

# run python
pushd projects/my-python-app && uv run main.py && popd
```
