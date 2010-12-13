// Agent a255 in project Agents_tcc
//policial oculto
/* Initial beliefs and rules */
comecar.
/* Initial goals */


/* Plans */
+comecar:true<-comeca.
+nivelSuspeitaIncrementado(Agente,Valor):Valor>4<-prender(Agente).
+nivelSuspeitaIncrementado(Agente,Valor):Valor<=4<-monitorar(Agente).
