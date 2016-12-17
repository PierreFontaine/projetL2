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
### Historique d'issues


#### [17 Dec 2016] Améliorations affichage et sauvegarde

Le programme demande maintenant le pseudo du joueur pour la sauvegarde dans un encart au milieu de la fenêtre.

Ajout de la fonction tetris qui quand 4 ligne sont remplis informe le joueur qu'il a effectué un tetris !

#### [11 Dec 2016] Début du mode de jeu alternatif

Commencement du mode de jeux alternatif, pas mal de correction, des couleurs et de l'animation sur le game over !

#### [9 Dec 2016] Son et résolutions de bugs

Ajout du son et code refractoring.

#### [3 Dec 2016] menu améliorations

Amélioration du menu, il reste des problèmes d'affichage et un segmentation fault qui vient surement de ncurses.

#### [25 Nov 2016] Rectifications

  Semaine de code refractoring :

  - plus de var glob
  - meilleur gestion de la grille d'aff, # et | enlevés

  - nouveau bug de segmentation pas très net ...

#### [18 Nov 2016] Amelioration et nouveautés

  Prise en compte des observation du mail, ajout de la libraire "ncurses" mais problème à l'affichage, en effet c'est comme si "\n" n'était pas pris en compte

#### [11 Nov 2016] SDL INITIALISEE

  Makefile amélioré pour OS X et Debian, sa modularité peut encore être amélioré.


  WorkAround :
  La version terminal utilisera la librairie "pthread", la version graphique utilisera la SDL qui semble avoir un system de gestion signaux donc on se passera ici de "pthread" ce qui solutionnera les bugs



#### [9 Nov 2016] SDL EN COURS DE PREPARATION

  Création d'un makefile permettant la compilation aussi bien sur Linux que sur Mac OS X.

  Problème d'utilisation de la Librairie Pthread et SDL, 64/32 bits #10

#### [7 Nov 2016] Problème de génération de nbre aléa entre 0 et 6

  La fonction random affichait toujours le même nombre pour 7, ceci est résolu. #5

### Objectifs

  Dans un premier temps réaliser un Tetris en ASCII pour y jouer dans le terminal et dans un deuxième temps l'implémenter avec ~~GTK+~~ SDL.

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
  - [x] Fonctions spé liées au fonctionnement du jeu
    - [x] rotation et verification
    - [x] déplacement et verification
    - [x] mise en pause
    - [x] gestion du score
    - [x] menu
  - [x] Fonctions spé liées à l'interaction H/M
    - [x] Association des touches à un évenement
  - [x] makefile

### Problèmes actuels

- ~~débordement de tableau~~
- ~~problème de rotation => changement de figure~~
- ~~fonction lancée du Thread ne bloque pas le main, pb pour pause()~~
- ~~augmenter la vitesse de la pièce~~
- ~~suppression des lignes, il subsiste un bug~~
