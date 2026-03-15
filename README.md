# TAMK Software Engineering Thesis

Title: Multilanguage and multiarchitecture monorepo managment and development  
Nimi: Monikielisen ja moniarkkitehtuurisen yhdistetyn koodivaraston hallinta ja kehitys

to run dev we need some system dependencies:

```bash
# for mac we can use homebrew
brew install node pnpm uv
```

and we need to have .env file in each project

```bash
for dir in ./projects/*; do ln -s ../../.env.example "$dir/.env"; done
```

to dev run all projects:

```bash
pnpm run -r --parallel dev
```
