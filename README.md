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
pnpm run -r --parallel dev

# run python
uv run projects/my-python-app/main.py
```
