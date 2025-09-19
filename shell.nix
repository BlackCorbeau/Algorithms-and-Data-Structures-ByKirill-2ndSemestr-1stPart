{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
    nativeBuildInputs = [
        pkgs.gcc
        pkgs.gdb
        pkgs.cmake
        pkgs.pkg-config
        pkgs.ninja
    ];

    shellHook = ''
        export CC=${pkgs.gcc}/bin/gcc
        export CXX=${pkgs.gcc}/bin/g++
        export LD_LIBRARY_PATH="${
            pkgs.lib.makeLibraryPath [
                pkgs.stdenv.cc.cc.lib
            ]
        }:$LD_LIBRARY_PATH"
        export CPLUS_INCLUDE_PATH="$PWD/include:$CPLUS_INCLUDE_PATH"
    '';
}
