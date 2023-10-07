{
  pkgs,
  cmake,
  ninja,
  qt5,
  mpv,
}:
pkgs.stdenv.mkDerivation {
  name = "mediaclient";
  nativeBuildInputs = [cmake ninja qt5.wrapQtAppsHook];
  buildInputs = [qt5.qtbase qt5.qtwebview qt5.qtwayland mpv];
  src = ./src;
}
