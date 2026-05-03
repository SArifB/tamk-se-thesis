{
  description = "thesis monorepo";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
    rust-overlay = {
      url = "github:oxalica/rust-overlay";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs =
    {
      # self,
      nixpkgs,
      flake-utils,
      rust-overlay,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        overlays = [ (import rust-overlay) ];
        pkgs = import nixpkgs {
          inherit system overlays;
        };
      in
      with pkgs;
      {
        devShells = {
          default = mkShell {
            buildInputs = [
              # Build tools
              clang
              cmake
              ninja
              emscripten
              wasm-pack
              podman
              podman-compose

              # Package managers
              nodejs
              pnpm
              python314
              uv
              (rust-bin.stable.latest.default.override {
                extensions = [ "rust-src" ];
                targets = [ "wasm32-unknown-unknown" ];
              })

              # Nix helpers
              nixd
              nil
            ];
          };

          py-app1-container = mkShell {
            packages = [
              bash
              cacert
              curl
              python314
              uv
            ];
          };

          js-app1-container = mkShell {
            packages = [
              bash
              cacert
              git
              nodejs
              pnpm

              clang
              cmake
              ninja
              emscripten
              wasm-pack
              (rust-bin.stable.latest.minimal.override {
                targets = [ "wasm32-unknown-unknown" ];
              })
            ];
          };

          js-app2-container = mkShell {
            packages = [
              bash
              cacert
              nodejs
              pnpm
            ];
          };
        };

        packages =
          let
            cpp-app1 = stdenv.mkDerivation {
              pname = "cpp-app1";
              version = "0.1.0";

              src = ./.;

              nativeBuildInputs = [
                clang
                cmake
                ninja
              ];

              # dont use default cmake setup that changes to build dir
              dontUseCmakeConfigure = true;

              configurePhase = ''
                runHook preConfigure
                cmake -B build/release -G Ninja \
                  -DCMAKE_BUILD_TYPE=Release \
                  -DTHESIS_BUILD_CPP_APP1=true \
                  -DTHESIS_BUILD_CPP_LIB1=true
                runHook postConfigure
              '';

              buildPhase = ''
                runHook preBuild
                cmake --build build/release --target cpp-app1
                runHook postBuild
              '';

              installPhase = ''
                runHook preInstall
                cmake --install build/release --prefix $out
                runHook postInstall
              '';
            };

            cpp-app2 = stdenv.mkDerivation {
              pname = "cpp-app2";
              version = "0.1.0";

              src = ./.;

              nativeBuildInputs = [
                clang
                cmake
                ninja
              ];

              # dont use default cmake setup that changes to build dir
              dontUseCmakeConfigure = true;

              configurePhase = ''
                runHook preConfigure
                cmake -B build/release -G Ninja \
                  -DCMAKE_BUILD_TYPE=Release \
                  -DTHESIS_BUILD_CPP_APP2=true \
                  -DTHESIS_BUILD_C_LIB1=true
                runHook postConfigure
              '';

              buildPhase = ''
                runHook preBuild
                cmake --build build/release --target cpp-app2
                runHook postBuild
              '';

              installPhase = ''
                runHook preInstall
                cmake --install build/release --prefix $out
                runHook postInstall
              '';
            };

            cpp-app3 = stdenv.mkDerivation {
              pname = "cpp-app3";
              version = "0.1.0";

              src = ./.;

              nativeBuildInputs = [
                clang
                cmake
                ninja
                git
                cacert
                rust-bin.stable.latest.minimal
              ];

              HOME = "/tmp";

              shellHook = ''
                export CARGO_HOME="$HOME/cargo"
                export RUSTUP_HOME="$HOME/rustup"
                export TMPDIR="$HOME"
              '';

              # dont use default cmake setup that changes to build dir
              dontUseCmakeConfigure = true;

              configurePhase = ''
                runHook preConfigure
                cmake -B build/release -G Ninja \
                  -DCMAKE_BUILD_TYPE=Release \
                  -DTHESIS_BUILD_CPP_APP3=true \
                  -DTHESIS_BUILD_CPP_LIB2=true \
                  -DTHESIS_BUILD_RUST_LIB1=true
                runHook postConfigure
              '';

              buildPhase = ''
                runHook preBuild
                cmake --build build/release --target cpp-app3
                runHook postBuild
              '';

              installPhase = ''
                runHook preInstall
                cmake --install build/release --prefix $out
                runHook postInstall
              '';
            };

            rust-app1 = stdenv.mkDerivation {
              pname = "rust-app1";
              version = "0.1.0";

              src = ./.;

              nativeBuildInputs = [
                clang
                cmake
                ninja
                git
                cacert
                rust-bin.stable.latest.minimal
              ];

              HOME = "/tmp";

              shellHook = ''
                export CARGO_HOME="$HOME/cargo"
                export RUSTUP_HOME="$HOME/rustup"
                export TMPDIR="$HOME"
              '';

              # dont use default cmake setup that changes to build dir
              dontUseCmakeConfigure = true;

              # we need to define these ourselves to bypass cmake defaults
              configurePhase = ''
                runHook preConfigure
                runHook postConfigure
              '';

              # we need to define these ourselves to bypass cmake defaults
              buildPhase = ''
                runHook preBuild
                runHook postBuild
              '';

              installPhase = ''
                runHook preInstall
                cargo install --path projects/rust-app1 --root $out
                runHook postInstall
              '';
            };
          in
          {
            inherit
              cpp-app1
              cpp-app2
              cpp-app3
              rust-app1
              ;

            default = symlinkJoin {
              name = "default";
              paths = [
                cpp-app1
                cpp-app2
                cpp-app3
                rust-app1
              ];
            };

          };
      }
    );
}
