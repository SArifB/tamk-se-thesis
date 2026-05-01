{ pkgs, system }:

let
  manifest = builtins.fromJSON (builtins.readFile ./buck2.json);

  platformkey =
    {
      x86_64-linux = "linux-x86_64";
      aarch64-linux = "linux-aarch64";
      x86_64-darwin = "macos-x86_64";
      aarch64-darwin = "macos-aarch64";
    }
    .${system} or (throw "buck2: unsupported system ${system}");

  entry = manifest.platforms.${platformkey};
  provider = builtins.head entry.providers;
in
pkgs.stdenv.mkDerivation {
  pname = "buck2";

  version =
    let
      m = builtins.match ".*/download/([^/]+)/.*" provider.url;
    in
    builtins.elemAt m 0;

  src = pkgs.fetchurl {
    url = provider.url;
    sha256 = entry."nix-digest";
  };

  nativeBuildInputs = [ pkgs.zstd ];
  dontUnpack = true;

  installPhase = ''
    mkdir -p $out/bin
    zstd -d $src -o buck2
    chmod +x buck2
    mv buck2 $out/bin/buck2
  '';
}
