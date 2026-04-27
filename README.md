# TAMK Software Engineering Thesis

Title: Multilanguage and multiarchitecture monorepo managment and development  
Nimi: Monikielisen ja moniarkkitehtuurisen yhdistetyn koodivaraston hallinta ja kehitys

This is an example of a basic typescript and python monorepo.
It does not use docker or anything else to abstract the architecture its running on, other than
the interpreters it uses.
There is also no proper caching strategy or build architecture so if we had ci/cd it would
rebuild everything from scratch every time.
There is also no reproducibility other than the lock files pnpm and uv create.

Deploying this project to production would be relatively easy but not scalable.
We could use a bunch of build scripts and reverse proxies like caddy or nginx to build and
serve this monorepo and process managers like systemd or launchd, but we would have to make our
own tools and automation scripts to reduce maintenance.

## Run Instructions

to run dev we need some system dependencies:

```bash
# for mac we can use homebrew
brew install node pnpm uv
```

and we need to have .env file in each project

```bash
pnpm run link-example-env
```

to dev run all projects:

```bash
pnpm run -r --parallel dev
```
