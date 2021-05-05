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

`man perror`

Confira, na Seção SEE ALSO do manual acima, indicações de outros manuais associados que apresentem uma introdução ao tratamento de erros. Por exemplo, em sistemas BSD, `man 2 intro`

Busque observar:
* Quem deve ser testado se vale -1? (O valor tem de ser -1?)
* EACCES e similares são macros?
* Todo erro tem um número de erro e uma mensagem de erro?
* Por que não precisamos saber o número de erro?

## Passo 1.2 
Modifique o programa `unlink_delete_me.c` para incluir tratamento de erros, mostrando uma mensagem de erro. Obviamente, use a mensagem de erro existente no sistema.

## Como o seu programa retorna erro

Quando é a vez do seu programa retornar a informação de erro, isso costuma ser feito por intermédio da função em C `exit`, da `stdlib.h`.

A convenção mais prevalente é a de que o valor retornado é 0 quando o programa é bem sucedido.

O valor de retorno pode ser obtido pelo usuário na linha de comando do *shell* executando o seguinte comando imediatamente após: `echo $?`

Sobre os erros em si, cada programa apresenta uma convenção própria para o código de erro. Valores negativos são inconvenientes, pois nem toda interface está configurada para o formato de complemento de 2.

# Atividade 2 - Metadados de arquivos

Objetivos:
* Conhecer os conceitos de propriedade, grupos e permissões (propriedade remete a proprietário, dono, *owner*) [esse é um recorte para foco]
* Operar leitura e alteração de permissões, com comandos no *shell* e com chamadas de sistema na programação
* Um ponto secundário e menos conhecido são os bits especiais, dentre eles o *stick bit* 

## Passo 2.1

Execute o comando

`ls -l unlink_delete_me.c`

Entenda como o comando `ls` convenciona apresentar proprietário, grupos e permissões.

`man ls`

Explore manuais associados, tais como `man 1 chmod` e `man sticky`

Modifique as permissões de unlink_delete_me.c. Por exemplo, retire a permissão de escrita do proprietário.

## Passo 2.2 (Opcional)

Através de comandos, crie os grupos `bell` e `berkeley`. Depois, crie os usuários `ken` e `dennis` no grupo `bell` e `bill` no `berkeley`.

Logue como o usuário ken, crie uma hierarquia de diretórios, modifique permissões. Logue como os demais usuários e tente acessar e modificar arquivos.

Tente observar os efeitos dos bits especiais (aqueles que são possíveis de observar, como o *sticky bit* em diretórios.

## Passo 2.3

Realize operações equivalentes de leitura e escrita, mas, desta vez, programaticamente, através das chamadas de sistema `stat` e `chmod`.

Observe que `chmod` é o nome tanto de um comando quanto de uma chamada de sistema, portanto, há o `man 1 chmod` e o `man 2 chmod`.

Mais especificamente, comece com o programa `leitura`, que imprime a mensagem "O arquivo 'delete.me' está com a permissão de escrita para o dono" quando isso é verdade ou uma mensagem com a negação, caso contrário.

Depois faça o programa `escrita`, que inverte o status da permissão de escrita do do dono do arquivo `delete.me`.

## Passo 2.4 (Opcional)

Faça um programa que apresenta todas as permissões de um arquivo ou diretório segundo a convenção do comando `ls`. Adicionalmente, informe também se é um arquivo ou se é um diretório.

## Passo 2.5

Procure saber sobre as chamadas de sistema `umask` e `access`.


