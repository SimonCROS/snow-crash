Sur l'exemple dans le sujet, on voit `su flag00`. flag00 est donc un utilisateur dans level00.

On peut donc faire un find -user flag00 pour check tout les fichier accessible par flag00, ainsi  on trouve `/usr/sbin/john`

En regardant le contenu du fichier,on trouve un message crypté `cdiiddwpgswtgt`, qui est un chiffrement de Cesar avec un decalage de 11.

Quand on fait le decalage on obtient comme resultat `nottoohardhere`

On peut donc maintenant se connecter à flag00 avec ce mot de passe.
