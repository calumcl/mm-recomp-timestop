{
  description = "MMRecomp Template Development Environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        crossPkgs = import nixpkgs {
          inherit system;
          crossSystem = { config = "mips64-elf"; };
        };
      in
      {
        devShells.default = pkgs.mkShell {
          packages = [
            pkgs.pkg-config
            pkgs.capstone
            pkgs.makeWrapper
            pkgs.clang.cc
            pkgs.llvmPackages.lld
            pkgs.unzip
            pkgs.bear
            crossPkgs.buildPackages.binutilsNoLibc
          ];
        };
      });
}