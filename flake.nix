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

              # Package managers
              nodejs
              pnpm
              python314
              uv
              rust
              buck2
              reindeer

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

        packages.hello = hello;
      }
    );
}
