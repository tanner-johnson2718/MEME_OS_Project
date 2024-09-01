{ stdenv, lib } :
let
    fs = lib.fileset;
    sourceFiles = ./hello2.c;
    exeName = "hello2";
in

# Print the source files
fs.trace sourceFiles

stdenv.mkDerivation {
    name = "hello2";
    pname = "hello2";
    version = "0.0.1";
    src = fs.toSource {
        root = ./.;
        fileset = sourceFiles;
    };

    buildPhase = ''
        gcc hello2.c -o ${exeName}
    '';

    installPhase = ''
        mkdir -p $out/bin
        cp ${exeName} $out/bin
    '';
    
    shellHook = ''
    echo "Nix Shell Starting up!"
    '';

    # builder = builder.sh   -> Can also overwrite the default build script 
    # with this
}