On voit un fichier level09 à la racine du home, qui s'execute avec les permissions de `flag10`, ainsi qu'un autre fichier `token` appartenant à flag10 et ne pouvant être lu que par ce dernier.
`./level10` nous indique qu'un argument doit être passé, ainsi qu'un host qui recevra le contenu du fichier.

La technique du lien symbolique ne fonctionne plus, mais on voit que access est appelé. Si aucune autre vérification est faite avant la lecture du fichier, une race condition peut peut-être être faite.

