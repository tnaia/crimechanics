
A pasta src contém os arquivos .java e .cpp, além do Makefile do jogo.

Arquivos main-nomeClasse.cpp são fontes para teste de cada uma das
classes.

Decisões de estrutura


SOBRE O PROTOCOLO

Aqui está uma possível troca de mensagens entre o C++ e o Java.

1: CppParaJava: IniciaDialogo(Policial)
2: JavaParaCpp: IdDoNC (IDInstanciaPolicial)
3: CppParaJava: EstimuloAgente( IDInstancia, Estimulo1, Estimulo2,
   ...)
...
8: CppParaJava: EscolhaAgente (IDInstancia, TipoEscolha1,
   TipoEscolha2, ...)

Comentários:

1: Avisa que um diálogo começou. O java deve cuidar de instanciar esse
agente se ele ainda não existe, ou simplesmente se preparar para
ainteração que vai acontecer. Existem outras mensagens que o C++ pode
enviar (e enviará) para o Java, pedindo IDs de agentes.
   Digamos, A mensagem TheSecuritySpecialist pede para o java dizer
qual o id desse agente (só deve haver um desse e de cada um dos outros
especialistas). Se esse agente ainda não estiver instanciado, essa
mensagem serve para pedir sua instanciação. No início (ou carga) de um
jogo, o C++ pede o id de cada um dos especialistas.
   
2: O Java fornece um número de referência para que o C++ use sempre
que for falar com esse NPC.

3: As falas ou ações que acontecem no jogo enviam mensagens para os
agentes associados. Num diálogo, esses estímulos são algo do tipo
FalaSuspeita, PropostaSuborno, etc. (a lista dos Estímulos está em um
arquivo que tanto o C++ quanto o Java lêem).

...

8: Oferece ao agente uma gama de escolhas. Essas escolhas são os tags
das opções de diálogo que o NPC tem. Ao BDI cabe optar pela que
"melhor expressa" seu estado de espírito.


