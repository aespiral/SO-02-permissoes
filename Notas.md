# Aula 02 - Tutorial permissões - Sistemas Operacionais II

## Objetivos
* Introdução a tratamento de erros de chamadas de sistema Unix
* Introdução ao *workflow* do Github Classroom
* Chamadas de sistema para acessar e modificar metadados de arquivos
* Especialmente: propriedade, grupos e permissões 

## Bibliografia
LEROY, X.; RÉMY, D. *Unix system programming in Ocaml*. 2014. Capítulo 2.

# Atividade 1 - Tratamento de erros nas chamadas de sistema Unix

## Passo 1.1 
Consulte

`man 2 intro`

`man perror`

Busque observar:
* Quem deve ser testado se vale -1? (O valor tem de ser -1?)
* EACCES e similares são macros?
* Todo erro tem um número de erro e uma mensagem de erro?
* Por que não precisamos saber o número de erro?

## Passo 1.2 
Modifique o programa `unlink_delete_me.c` para incluir tratamento de erros, mostrando uma mensagem de erro. Obviamente, use a mensagem de erro existente no sistema.

