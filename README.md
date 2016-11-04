# projetL2 [![Build Status](https://travis-ci.org/PierreFontaine/projetL2.svg?branch=master)](https://travis-ci.org/PierreFontaine/projetL2) [![Join the chat at https://gitter.im/projetL2Room/Lobby](https://badges.gitter.im/projetL2Room/Lobby.svg)](https://gitter.im/projetL2Room/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)



## Compilation

### pré requis

Vous êtes sous UNIX (Linux ou Mac), et disposez de Make.

### Make fait le taff pour vous !

Télechargez le dossier et accedez y avec le terminal !

```sh
  cd pathToDir/game/
  make
  ./programme
```

## Tetris

### Objectifs

  Dans un premier temps réaliser un Tetris en ASCII pour y jouer dans le terminal et dans un deuxième temps l'implémenter avec GTK+

### En cours

  Utilisation massive de structure pour faire un maximum d'encapsulation.

  Utilisation d'un Thread pour la lecture des touches.

  Création de bibliothèque sans problème de "circular depedencies"
  <!-- -->
  Création du stuff

  - [x] Fonctions spé d'affichage console
    - [x] Couleurs
    - [x] Layout
    - [x] Affichage des pieces
    - [x] Suppression de pieces
  - [ ] Fonctions spé liées au fonctionnement du jeu
    - [ ] rotation et verification
    - [x] déplacement et verification
    - [ ] mise en pause
    - [ ] gestion du score
  - [ ] Fonctions spé liées à l'interaction H/M
    - [ ] Association des touches à un évenement
  - [x] makefile
### Problèmes actuels

- débordement de tableau
- problème de rotation => changement de figure
- fonction lancée du Thread ne bloque pas le main


## Bataille Navale
