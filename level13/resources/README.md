Dans le repertoire, on a un executable `level13`
Lorsqu'on l'execute, il nous affiche: `UID 2013 started us but we we expect 4242`

En effectuant la commande strings on peut voir: 

```
UID %d started us but we we expect %d
boe]!ai0FB@.:|L6l@A?>qJ}I
your token is %s
;*2$"$
```

On decide de l'inspecter avec `gdb` et en desassemblant le main on obtient:

```
Dump of assembler code for function main:
   0x0804858c <+0>:     push   %ebp
   0x0804858d <+1>:     mov    %esp,%ebp
   0x0804858f <+3>:     and    $0xfffffff0,%esp
   0x08048592 <+6>:     sub    $0x10,%esp
   0x08048595 <+9>:     call   0x8048380 <getuid@plt>
   0x0804859a <+14>:    cmp    $0x1092,%eax
   0x0804859f <+19>:    je     0x80485cb <main+63>
   0x080485a1 <+21>:    call   0x8048380 <getuid@plt>
   0x080485a6 <+26>:    mov    $0x80486c8,%edx
   0x080485ab <+31>:    movl   $0x1092,0x8(%esp)
   0x080485b3 <+39>:    mov    %eax,0x4(%esp)
   0x080485b7 <+43>:    mov    %edx,(%esp)
   0x080485ba <+46>:    call   0x8048360 <printf@plt>
   0x080485bf <+51>:    movl   $0x1,(%esp)
   0x080485c6 <+58>:    call   0x80483a0 <exit@plt>
   0x080485cb <+63>:    movl   $0x80486ef,(%esp)
   0x080485d2 <+70>:    call   0x8048474 <ft_des>
   0x080485d7 <+75>:    mov    $0x8048709,%edx
   0x080485dc <+80>:    mov    %eax,0x4(%esp)
   0x080485e0 <+84>:    mov    %edx,(%esp)
   0x080485e3 <+87>:    call   0x8048360 <printf@plt>
   0x080485e8 <+92>:    leave  
   0x080485e9 <+93>:    ret    
End of assembler dump.
```

Ici, il y'a 3 lignes qui nous interesse:
-  0x0804859a <+14>:    cmp    $0x1092,%eax Où il y'a une comparaison.
-  0x080485ba <+46>:    call   0x8048360 <printf\@plt> Qui affiche le texte.
-  0x080485d2 <+70>:    call   0x8048474 <ft_des> Qui donne le token.

Si on decide d'aller directement a ft_des juste avant le cmp, on obtient: `your token is %zqSP:OEB5>J56MI?U2GBSC;OI3S1N@71HKZ4;` 

Ce code n'est pas bon.

On decide donc d'essayer de lui donner la bonne valeur (4242)

Pour ce faire, on met un breakpoint juste avant la comparaison, on lance l'execution, on change la valeur de eax et on continue l'execution.

```
break *0x0804859a
run
set $eax=4242
next
```

On obient ainsi le mot de passe pour le level14