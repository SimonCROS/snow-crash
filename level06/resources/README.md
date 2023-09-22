On voit qu'il y a deux fichiers: `level06` et `level06.php`.
`level06` a des permissions spéciales qui éxécutent le programme avec les permissions du propriétaire : flag06.

Le contenu de `level06.php` utilise plusieurs `preg_replace`, dont un qui prend le paramètre de `level06` en tant que contenu dans lequel rechercher une partie.
```php
$a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
```
On voit que la regex utilise '/e', une option dépréciée puis supprimée, mais qui est encore présente sur la version php installée.
/e signifie que la partie qui est remplacé va être éxécutée en php, et la partie "\\2" référence le deuxième groupe de la regex (donc `(.*)`).

Donc on peut injecter du code dans `y("<input>")` via `[x <input>]`.
Si on essaye de mettre des guillemets, ils sont échapés donc cela ne fonctionnera pas.
On peut utiliser les accolades pour insérer du code dans la string :
```bash
echo '[x {${shell_exec(getflag)}}]' > exploit
./level06 exploit
```
