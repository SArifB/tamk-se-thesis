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
        rust = pkgs.rust-bin.stable.latest.default.override {
          extensions = [ "rust-src" ];
          targets = [ "wasm32-unknown-unknown" ];
        };
        buck2 = import ./nix/buck2.nix {
          inherit pkgs system;
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
              buck2
              reindeer

              # Package managers
              nodejs
              pnpm
              python314
              uv
              rust

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
              rust
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

        packages = rec {
          default = symlinkJoin {
            name = "default";
            paths = [
              cpp-app1
              cpp-app2
              cpp-app3
              rust-app1
            ];
          };

          cpp-app1 = stdenv.mkDerivation {
            pname = "cpp-app1";
            version = "0.1.0";

            src = ./.;

            nativeBuildInputs = [
              clang
              buck2
              cacert
            ];

            installPhase = ''
              export HOME=$TMPDIR

              APP=$(buck2 build //projects/cpp-app1 --show-output --console none | awk '{print $2}')

              mkdir -p $out/bin
              cp "$APP" $out/bin/cpp-app1
            '';
            # '';
          };

          cpp-app2 = stdenv.mkDerivation {
            pname = "cpp-app2";
            version = "0.1.0";

            src = ./.;

            nativeBuildInputs = [
              clang
              buck2
              cacert
            ];

            installPhase = ''
              export HOME=$TMPDIR

              APP=$(buck2 build //projects/cpp-app2 --show-output --console none | awk '{print $2}')

              mkdir -p $out/bin
              cp "$APP" $out/bin/cpp-app2
            '';
          };

          cpp-app3 = stdenv.mkDerivation {
            pname = "cpp-app3";
            version = "0.1.0";

            src = ./.;

            nativeBuildInputs = [
              pkgs.rust-bin.stable.latest.minimal
              clang
              buck2
              cacert
            ];

            installPhase = ''
              export HOME=$TMPDIR

              APP=$(buck2 build //projects/cpp-app3 --show-output --console none | awk '{print $2}')

              mkdir -p $out/bin
              cp "$APP" $out/bin/cpp-app3
            '';
          };

          rust-app1 = stdenv.mkDerivation {
            pname = "rust-app1";
            version = "0.1.0";

            src = ./.;

            nativeBuildInputs = [
              pkgs.rust-bin.stable.latest.minimal
              clang
              buck2
              cacert
            ];

            installPhase = ''
              export HOME=$TMPDIR

              APP=$(buck2 build //projects/rust-app1 --show-output --console none | awk '{print $2}')

              mkdir -p $out/bin
              cp "$APP" $out/bin/rust-app1
            '';
          };

        };

      }
    );
}
