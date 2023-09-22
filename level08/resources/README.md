On voit un fichier level08 à la racine du home, qui s'execute avec les permissions de `flag08`, ainsi qu'un autre fichier `token` appartenant à flag08 et ne pouvant être lu que par lui.
Lors de l'execution de level08, on peut voir qu'il s'utilise avec un argument, qui est un fichier à lire.

Étant donné qu'on souhaite obtenir le contenu de token, on essaye
`./level08 token`
Mais le programme test les permissions et print "You may not access 'token'".
Vu que le programme a la permission de lire 'token', cela signifie que le check des permissions est effectué en amont, mais strings ne montre ni l'utilisation de `stat`, ni `access`.

Une idée a été d'essayer de donner l'impression au programme qu'il avait le droit avec un lien symbolique sur token.
```sh
$> ln -s token a
$> ./level08 a
quif5eloekouj29ke0vouxean
```
On peut maintenant se connecter à flag08 avec le token et lancer getflag.
