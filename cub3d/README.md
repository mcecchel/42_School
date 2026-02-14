# cub3d

![Language](https://img.shields.io/badge/language-C-blue)
![Graphics](https://img.shields.io/badge/graphics-MiniLibX-orange)
![School](https://img.shields.io/badge/school-42-black)
![Status](https://img.shields.io/badge/status-completed-success)

## 📌 Overview

**cub3d** è un progetto del curriculum della scuola 42 che consiste nello sviluppo di un semplice motore grafico 3D utilizzando la tecnica del **raycasting**, ispirato al leggendario gioco *Wolfenstein 3D*.

Il programma renderizza una visuale in prima persona di un labirinto 3D partendo da una rappresentazione 2D della mappa. Il motore calcola la distanza dalle pareti e le proietta sullo schermo per creare l’illusione della profondità.

Questo progetto introduce i principi fondamentali della computer graphics e del funzionamento dei primi game engine 3D.

---

## 🎯 Obiettivi del progetto

* Implementare un motore grafico 3D base in C
* Comprendere e implementare il raycasting
* Gestire input da tastiera e movimento del giocatore
* Effettuare parsing e validazione di file di configurazione
* Gestire texture, colori e rendering
* Migliorare la gestione della memoria e l’architettura del codice

---

## 🕹️ Features

* Rendering 3D in prima persona
* Movimento fluido del giocatore
* Rotazione della visuale
* Texture sulle pareti
* Colori personalizzati per pavimento e soffitto
* Parsing di file `.cub`
* Validazione completa della mappa
* Gestione degli input da tastiera
* Rendering in tempo reale

---

## 🧠 Come funziona il Raycasting

Il raycasting funziona inviando un raggio per ogni colonna dello schermo dal punto di vista del giocatore.

Per ogni raggio, il programma:

1. Calcola la direzione del raggio
2. Determina dove colpisce una parete
3. Calcola la distanza dalla parete
4. Disegna una linea verticale proporzionale alla distanza

Questo crea l’illusione di uno spazio tridimensionale.

---

## 📂 Struttura del progetto

```
cub3d/
├── includes/
│   └── cub3d.h
├── src/
│   ├── main.c
│   ├── parsing/
│   ├── rendering/
│   ├── movement/
│   └── utils/
├── textures/
├── maps/
│   └── map.cub
├── Makefile
└── README.md
```

---

## ⚙️ Installazione

Clona la repository:

```bash
git clone https://github.com/username/cub3d.git
cd cub3d
```

Compila il progetto:

```bash
make
```

---

## ▶️ Utilizzo

Esegui il programma con una mappa:

```bash
./cub3d maps/map.cub
```

---

## 🎮 Controlli

| Tasto | Azione             |
| ----- | ------------------ |
| W     | Muovi avanti       |
| S     | Muovi indietro     |
| A     | Muovi a sinistra   |
| D     | Muovi a destra     |
| ←     | Ruota a sinistra   |
| →     | Ruota a destra     |
| ESC   | Esci dal programma |

---

Legenda:

* `1` → muro
* `0` → spazio vuoto
* `N/S/E/W` → posizione iniziale del giocatore

---

## 🧱 Tecnologie utilizzate

* C
* MiniLibX
* Matematica trigonometrica
* Raycasting
* Event handling
* Memory management

---

## 📚 Cosa ho imparato

Questo progetto mi ha permesso di comprendere:

* Come funzionano i motori grafici
* Le basi del rendering 3D
* La gestione degli eventi grafici
* L’ottimizzazione delle performance
* La progettazione di software strutturato

---

## 🚀 Possibili miglioramenti

* Minimappa
* Collisioni migliorate
* Sprite rendering
* Porte
* Nemici
* Mouse control
* Miglioramenti grafici

---

## 👤 Autore

**mcecchel & terzogode**

Studenti della scuola 42

---

## 📜 Licenza

Questo progetto è stato sviluppato come parte del curriculum della scuola 42 ed è destinato a scopi educativi.
