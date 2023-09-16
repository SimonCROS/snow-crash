Dans le fichier `/etc/passwd`, on peut voir
```txt
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

Le mot de passe `42hDRfypTqqnw` est hashé, on peut chercher un mot de passe correspondant à ce hash avec John the Ripper, qui va comparer ce hash à des mots de passes connus.

On obtient un seul résultat : `abcdefg`.
On peut donc maintenant se connecter à flag01 avec ce mot de passe.
