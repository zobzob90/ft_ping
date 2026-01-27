# 📡 ft_ping

Premier projet post tronc commun de l’école 42.

ft_ping est une implémentation en C du programme ping, permettant de tester la connectivité réseau entre une machine locale et une cible distante à l’aide du protocole ICMP (Internet Control Message Protocol).

# 🎯 Objectifs du projet

Ce projet vise à comprendre :
- le fonctionnement bas niveau du réseau
- l’utilisation des raw sockets
- la construction et l’analyse de paquets ICMP
- la gestion du temps (RTT) et des signaux

# 🌐 Qu’est-ce que ICMP ?

ICMP (Internet Control Message Protocol) est un protocole de la couche réseau utilisé pour le diagnostic et le contrôle des erreurs.
Le programme ping repose sur l’échange de messages :
- ICMP Echo Request
- ICMP Echo Reply
afin de mesurer la latence et la disponibilité d’une machine distante.

# 🛠️ Compilation & Utilisation
make
- sudo ./ft_ping [options] <destination>
- sudo ./ft_ping -v google.com
# ℹ️ Les raw sockets nécessitent les droits root.

# 📁 Arborescence du projet
```
├── inc
│   ├── icmp.h     # Définition des structures ICMP et fonctions associées
│   ├── ping.h     # Structure principale t_ping et prototypes globaux
│   └── utils.h    # Fonctions utilitaires
├── srcs
│   ├── icmp.c     # Construction et traitement des paquets ICMP
│   ├── init.c     # Initialisation du programme et du socket
│   ├── main.c     # Point d’entrée du programme
│   ├── parsing.c  # Parsing des arguments et gestion des flags
│   ├── ping.c     # Boucle principale du ping
│   └── utils.c    # Fonctions utilitaires (temps, affichage, erreurs…)
├── Makefile
```
