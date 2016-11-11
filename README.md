# projetL2 [![Build Status](https://travis-ci.org/PierreFontaine/projetL2.svg?branch=master)](https://travis-ci.org/PierreFontaine/projetL2) [![Join the chat at https://gitter.im/projetL2Room/Lobby](https://badges.gitter.im/projetL2Room/Lobby.svg)](https://gitter.im/projetL2Room/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)



## Compilation

### pré requis

Vous êtes sous UNIX (Linux ou Mac), et disposez de Make.


### Make fait le taff pour vous !

Télechargez le dossier et accèdez y avec le terminal !

```sh
  cd pathToDir/game/
  make
  ./programme
```

## Tetris
### historique d'issue
#### [11 Nov 2016] SDL INITIALISEE

  Makefile amélioré pour OS X et Debian, sa modularité peut encore être amélioré.
  ---
  WorkAround :
  La version terminal utilisera la librairie "pthread", la version graphique utilisera la SDL qui semble avoir un system de gestion signaux donc on se passera ici de "pthread" ce qui solutionnera les bugs


#### [9 Nov 2016] SDL EN COURS DE PREPARATION

  Création d'un makefile permettant la compilation aussi bien sur Linux que sur Mac OS X.

  Problème d'utilisation de la Librairie Pthread et SDL, 64/32 bits

### Objectifs

  Dans un premier temps réaliser un Tetris en ASCII pour y jouer dans le terminal et dans un deuxième temps l'implémenter avec GTK+

### En cours

  Utilisation massive de structure pour faire un maximum d'encapsulation.

  Utilisation d'un Thread pour la lecture des touches.

  Création de bibliothèque sans problèmes de "circular depedencies"
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
