On voit un fichier level11.lua à la racine du home, qui s'execute avec les permissions de `flag11`, 
On peut constater que c'est un serveur qui écoute sur le port 5151, demande un mot de passe, le hash, et le compare à un hash constant.

`prog = io.popen("echo "..pass.." | sha1sum", "r")`
hash le mot de passe donné, puis le résultat est comparé à
`f05d1d066fb246efe0c6f7d095f909a7a0cf34a0`

On peut essayer de brute force le hash sha1sum, par exemple via des sites en ligne tels que https://dcode.fr/hash-sha1, et qui arrive à trouver une solution : "NotSoEasy".

Le problème est que quand on teste
`echo NotSoEasy | sha1sum`, on obtient `62d39a9edac7bc1a68d816a5d9a491aa4e81fbcb`.
Après avoir cru à une erreur de dcode.fr, on a remarqué que `echo NotSoEasy` donne `NotSoEasy\n`, ce qui est différent.
Donc nouveau test avec printf `printf NotSoEasy | sha1sum`, et là, ça marche.

Maintenant, que peut-on en faire, vu que le programme lua utilise `echo`...
Il y a un argument, pris par echo, permettant d'afficher sans retour à la ligne: -n.
Et si on essaye dans le programme lua :
```bash
$> nc 127.0.0.1 5151
Password: -n NotSoEasy
Gz you dumb*
```
Ça marche !
Problème : pour l'instant, ça sert à rien...
Enfin si, ça sert à voir qu'on peut injecter du code.

Du coup, on peut essayer de terminer le echo, lancer getflag, mettre le résultat dans un fichier accessible et continuer le echo comme si rien ne s'était passé.
`; getflag > /tmp/flag11; chmod +rw /tmp/flag11; echo a`

Ne reste plus qu'à `cat /tmp/flag11`, et voilà le flag `fa6v5ateaw21peobuub8ipe6s` !
