Dans le dossier home du level02, il y a un fichier level02.pcap
C'est un fichier qui provient de Wireshark, un outil pour analyser un réseau.

On peut récupérer le fichier via
```bash
scp -P 4242 level02@192.168.64.8:/home/user/level02/level02.pcap .
```

Une fois ouvert dans Wireshark, on voit que deux adresses IP sont impliquées.
Les messages envoyés par 59.233.235.223 contiennent de la data comme "Login incorrect", on peut donc imaginer que c'est le serveur.
L'autre (59.233.235.218) envoie des régulièrement messages de 1 octet chacuns.

Si on récupère les octets un par un, on obtient
`6c 65 76 65 6c 58 0d 66 74 5f 77 61 6e 64 72 7f 7f 7f 4e 44 52 65 6c 7f 4c 30 4c 0d`
On voit une répétition de 7f, qui est le code hexa pour del, donc on peut imaginer que tous ces octets sont les touches de l'utilisateur, envoyés sur une session ssh.
`6c 65 76 65 6c 58 0d 66 74 5f 77 61 4e 44 52 65 4c 30 4c 0d`
En ASCII :
```txt
levelX
ft_waNDReL0L
```
Si on met en lien avec ce qu'envoie le serveur, on a
```txt
Login: levelX
Password: ft_waNDReL0L
```

On peut maintenant se log sur flag02 avec `ft_waNDReL0L`.
