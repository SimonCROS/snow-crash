On a aucune info, toutes les recherches a base de find ne donne rien.

Quand on lance getflag, on a l'habituel:  `Nope there is no token here for you sorry. Try again :)`.

On essaye donc un strings getflag et on voit une ligne: `You should not reverse this`

Du coup on decide de le reverse.

```bash
gdb /bin/getflag
disas main
```

Quand on run le programme, on obtient la ligne `You should not reverse this`.

On voit sur une ligne : `   0x080489a3 <+93>:    jmp    0x8048eb2 <main+1388> ` qui jump a la fin du programme.
On decide donc de mettre un breakpoint juste avant celui ci et on observe que les deux lignes au dessus affiche le `you should not reverse this`.

En analysant plus loin dans le main, on peut voir une repetition d'un meme patern (15x): 

```
   0x08048de5 <+1183>:  mov    0x804b060,%eax
   0x08048dea <+1188>:  mov    %eax,%ebx
   0x08048dec <+1190>:  movl   $0x8049220,(%esp)
   0x08048df3 <+1197>:  call   0x8048604 <ft_des>
   0x08048df8 <+1202>:  mov    %ebx,0x4(%esp)
   0x08048dfc <+1206>:  mov    %eax,(%esp)
   0x08048dff <+1209>:  call   0x8048530 <fputs@plt>
   0x08048e04 <+1214>:  jmp    0x8048e2f <main+1257>
```

On decide donc de faire un jump sur le debut de la derniere occurence de ce patern:
   0x08048de5 <+1183>:  mov    0x804b060,%eax

En continuant le programme a partir de ce point, on peut obtenir le flag.

