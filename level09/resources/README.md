On voit un fichier level09 à la racine du home, qui s'execute avec les permissions de `flag09`, ainsi qu'un autre fichier `token` appartenant à flag09 et pouvant être lu depuis level09.
`./level09` nous indique qu'un argument doit être passé.
`cat token` imprime des symboles non ascii `f4kmm6p|=�p�n��DB�Du{��`.

On essaye de lancer `./level09` avec une string, mais on obtient des changements étranges.
On peut essayer de comprendre les changements faits avec par exemple l'alphabet, ou juste une suite de `a`.
Par exemple `./level09 aaaaaaaaaaaaaaaaaaaaaaaaaa` donne `abcdefghijklmnopqrstuvwxyz`, donc level09 prend une string et augmente le code du caractère par son index.

On peut penser que c'est ce qui est arrivé au contenu du fichier de token, on va donc essayer de l'inverser avec un petit programme maison.
Le programme est dans "reverse.c".
`gcc level09/resources/reverse.c && ./a.out level09/resources/token`
On obtient le mot de passe de flag09 "f3iji1ju5yuevaus41q1afiuq".
