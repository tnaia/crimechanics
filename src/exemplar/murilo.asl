// Agent murilo in project exemplar

/* Initial beliefs and rules */

/* Initial goals */

!start.

/* Plans */

+!start : true <- .print("bom dia a todos!");definir(status).
+insultado : personalidade(grosso)& (estadoEmocional(bravo)|estadoEmocional(indiferente)) <- .print("nao preciso ouvir isso! POLICIA!").
+insultado : personalidade(simpatico)& estadoEmocional(feliz) <- .print("por que me ofende?");estadoEmocional(bravo).
+elogiado : personalidade(simpatico)& estadoEmocional(feliz) <- .print("vou lhe contar algumas coisas...");informar(capanga).
+elogiado : personalidade(simpatico)& estadoEmocional(indiferente) <- .print("o que voce deseja saber?");estadoEmocional(feliz).


