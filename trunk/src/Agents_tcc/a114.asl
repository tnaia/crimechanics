// Agent a114 in project Agents_tcc

/* Initial beliefs and rules */
started.
/* Initial goals */

/* Plans */
+estimulo(negativo):personalidade(simpatico)&estadoPsicologico(feliz)<-responder(amigavel);atualizar(crencas).

/*estimulo agmigavel*/

+estimulo(falaAmigavel):personalidade(rabugento)&estadoPsicologico(feliz)<-atualizarP(simpatico);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(rabugento)&estadoPsicologico(zangado)<-ataulizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(rabugento)&estadoPsicologico(apreensivo)<-ataulizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-ataulizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(rabugento)&estadoPsicologico(compreensivo)<-ataulizarEP(compreensivo);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(simpatico)&estadoPsicologico(feliz)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(simpatico)&estadoPsicologico(zangado)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(simpatico)&estadoPsicologico(apreensivo)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(simpatico)&estadoPsicologico(compreensivo)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(educado)&estadoPsicologico(feliz)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(educado)&estadoPsicologico(zangado)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(educado)&estadoPsicologico(apreensivo)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(educado)&estadoPsicologico(lisonjeado)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(educado)&estadoPsicologico(compreensivo)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(grosseiro)&estadoPsicologico(feliz)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(grosseiro)&estadoPsicologico(zangado)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(apressado)&estadoPsicologico(feliz)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(apressado)&estadoPsicologico(zangado)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(apressado)&estadoPsicologico(apreensivo)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(apressado)&estadoPsicologico(lisonjeado)<-muda(E);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(apressado)&estadoPsicologico(compreensivo)<-muda(E);removerEstimulo(falaAmigavel).

/*estimulo elogio*/

+estimulo(elogio):personalidade(rabugento)&estadoPsicologico(feliz)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(rabugento)&estadoPsicologico(zangado)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(rabugento)&estadoPsicologico(apreensivo)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(rabugento)&estadoPsicologico(compreensivo)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(simpatico)&estadoPsicologico(feliz)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(simpatico)&estadoPsicologico(zangado)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(simpatico)&estadoPsicologico(apreensivo)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(simpatico)&estadoPsicologico(compreensivo)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(educado)&estadoPsicologico(feliz)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(educado)&estadoPsicologico(zangado)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(educado)&estadoPsicologico(apreensivo)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(educado)&estadoPsicologico(lisonjeado)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(educado)&estadoPsicologico(compreensivo)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(grosseiro)&estadoPsicologico(feliz)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(grosseiro)&estadoPsicologico(zangado)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(apressado)&estadoPsicologico(feliz)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(apressado)&estadoPsicologico(zangado)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(apressado)&estadoPsicologico(apreensivo)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(apressado)&estadoPsicologico(lisonjeado)<-muda(E);removerEstimulo(elogio).
+estimulo(elogio):personalidade(apressado)&estadoPsicologico(compreensivo)<-muda(E);removerEstimulo(elogio).

/*estimulo insulto*/
+estimulo(insulto):personalidade(rabugento)&estadoPsicologico(feliz)<-muda(E).
+estimulo(insulto):personalidade(rabugento)&estadoPsicologico(zangado)<-muda(E).
+estimulo(insulto):personalidade(rabugento)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(insulto):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(insulto):personalidade(rabugento)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(insulto):personalidade(simpatico)&estadoPsicologico(feliz)<-muda(E).
+estimulo(insulto):personalidade(simpatico)&estadoPsicologico(zangado)<-muda(E).
+estimulo(insulto):personalidade(simpatico)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(insulto):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(insulto):personalidade(simpatico)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(insulto):personalidade(educado)&estadoPsicologico(feliz)<-muda(E).
+estimulo(insulto):personalidade(educado)&estadoPsicologico(zangado)<-muda(E).
+estimulo(insulto):personalidade(educado)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(insulto):personalidade(educado)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(insulto):personalidade(educado)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(insulto):personalidade(grosseiro)&estadoPsicologico(feliz)<-muda(E).
+estimulo(insulto):personalidade(grosseiro)&estadoPsicologico(zangado)<-muda(E).
+estimulo(insulto):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(insulto):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(insulto):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(insulto):personalidade(apressado)&estadoPsicologico(feliz)<-muda(E).
+estimulo(insulto):personalidade(apressado)&estadoPsicologico(zangado)<-muda(E).
+estimulo(insulto):personalidade(apressado)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(insulto):personalidade(apressado)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(insulto):personalidade(apressado)&estadoPsicologico(compreensivo)<-muda(E).

/*estimulo fala-timida*/
+estimulo(falaTimida):personalidade(rabugento)&estadoPsicologico(feliz)<-muda(E).
+estimulo(falaTimida):personalidade(rabugento)&estadoPsicologico(zangado)<-muda(E).
+estimulo(falaTimida):personalidade(rabugento)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(falaTimida):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(falaTimida):personalidade(rabugento)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(falaTimida):personalidade(simpatico)&estadoPsicologico(feliz)<-muda(E).
+estimulo(falaTimida):personalidade(simpatico)&estadoPsicologico(zangado)<-muda(E).
+estimulo(falaTimida):personalidade(simpatico)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(falaTimida):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(falaTimida):personalidade(simpatico)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(falaTimida):personalidade(educado)&estadoPsicologico(feliz)<-muda(E).
+estimulo(falaTimida):personalidade(educado)&estadoPsicologico(zangado)<-muda(E).
+estimulo(falaTimida):personalidade(educado)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(falaTimida):personalidade(educado)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(falaTimida):personalidade(educado)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(falaTimida):personalidade(grosseiro)&estadoPsicologico(feliz)<-muda(E).
+estimulo(falaTimida):personalidade(grosseiro)&estadoPsicologico(zangado)<-muda(E).
+estimulo(falaTimida):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(falaTimida):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(falaTimida):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(falaTimida):personalidade(apressado)&estadoPsicologico(feliz)<-muda(E).
+estimulo(falaTimida):personalidade(apressado)&estadoPsicologico(zangado)<-muda(E).
+estimulo(falaTimida):personalidade(apressado)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(falaTimida):personalidade(apressado)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(falaTimida):personalidade(apressado)&estadoPsicologico(compreensivo)<-muda(E).

/*estimulo inquisitivo*/
+estimulo(inquisitivo):personalidade(rabugento)&estadoPsicologico(feliz)<-muda(E).
+estimulo(inquisitivo):personalidade(rabugento)&estadoPsicologico(zangado)<-muda(E).
+estimulo(inquisitivo):personalidade(rabugento)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(inquisitivo):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(inquisitivo):personalidade(rabugento)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(inquisitivo):personalidade(simpatico)&estadoPsicologico(feliz)<-muda(E).
+estimulo(inquisitivo):personalidade(simpatico)&estadoPsicologico(zangado)<-muda(E).
+estimulo(inquisitivo):personalidade(simpatico)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(inquisitivo):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(inquisitivo):personalidade(simpatico)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(inquisitivo):personalidade(educado)&estadoPsicologico(feliz)<-muda(E).
+estimulo(inquisitivo):personalidade(educado)&estadoPsicologico(zangado)<-muda(E).
+estimulo(inquisitivo):personalidade(educado)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(inquisitivo):personalidade(educado)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(inquisitivo):personalidade(educado)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(inquisitivo):personalidade(grosseiro)&estadoPsicologico(feliz)<-muda(E).
+estimulo(inquisitivo):personalidade(grosseiro)&estadoPsicologico(zangado)<-muda(E).
+estimulo(inquisitivo):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(inquisitivo):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(inquisitivo):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(inquisitivo):personalidade(apressado)&estadoPsicologico(feliz)<-muda(E).
+estimulo(inquisitivo):personalidade(apressado)&estadoPsicologico(zangado)<-muda(E).
+estimulo(inquisitivo):personalidade(apressado)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(inquisitivo):personalidade(apressado)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(inquisitivo):personalidade(apressado)&estadoPsicologico(compreensivo)<-muda(E).

/*estimulo suspeito*/
+estimulo(suspeito):personalidade(rabugento)&estadoPsicologico(feliz)<-muda(E).
+estimulo(suspeito):personalidade(rabugento)&estadoPsicologico(zangado)<-muda(E).
+estimulo(suspeito):personalidade(rabugento)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(suspeito):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(suspeito):personalidade(rabugento)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(suspeito):personalidade(simpatico)&estadoPsicologico(feliz)<-muda(E).
+estimulo(suspeito):personalidade(simpatico)&estadoPsicologico(zangado)<-muda(E).
+estimulo(suspeito):personalidade(simpatico)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(suspeito):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(suspeito):personalidade(simpatico)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(suspeito):personalidade(educado)&estadoPsicologico(feliz)<-muda(E).
+estimulo(suspeito):personalidade(educado)&estadoPsicologico(zangado)<-muda(E).
+estimulo(suspeito):personalidade(educado)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(suspeito):personalidade(educado)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(suspeito):personalidade(educado)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(suspeito):personalidade(grosseiro)&estadoPsicologico(feliz)<-muda(E).
+estimulo(suspeito):personalidade(grosseiro)&estadoPsicologico(zangado)<-muda(E).
+estimulo(suspeito):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(suspeito):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(suspeito):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(suspeito):personalidade(apressado)&estadoPsicologico(feliz)<-muda(E).
+estimulo(suspeito):personalidade(apressado)&estadoPsicologico(zangado)<-muda(E).
+estimulo(suspeito):personalidade(apressado)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(suspeito):personalidade(apressado)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(suspeito):personalidade(apressado)&estadoPsicologico(compreensivo)<-muda(E).


/*estimulo suspeito*/
+estimulo(inquestionavel):personalidade(rabugento)&estadoPsicologico(feliz)<-muda(E).
+estimulo(inquestionavel):personalidade(rabugento)&estadoPsicologico(zangado)<-muda(E).
+estimulo(inquestionavel):personalidade(rabugento)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(inquestionavel):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(inquestionavel):personalidade(rabugento)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(inquestionavel):personalidade(simpatico)&estadoPsicologico(feliz)<-muda(E).
+estimulo(inquestionavel):personalidade(simpatico)&estadoPsicologico(zangado)<-muda(E).
+estimulo(inquestionavel):personalidade(simpatico)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(inquestionavel):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(inquestionavel):personalidade(simpatico)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(inquestionavel):personalidade(educado)&estadoPsicologico(feliz)<-muda(E).
+estimulo(inquestionavel):personalidade(educado)&estadoPsicologico(zangado)<-muda(E).
+estimulo(inquestionavel):personalidade(educado)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(inquestionavel):personalidade(educado)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(inquestionavel):personalidade(educado)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(inquestionavel):personalidade(grosseiro)&estadoPsicologico(feliz)<-muda(E).
+estimulo(inquestionavel):personalidade(grosseiro)&estadoPsicologico(zangado)<-muda(E).
+estimulo(inquestionavel):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(inquestionavel):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(inquestionavel):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-muda(E).
+estimulo(inquestionavel):personalidade(apressado)&estadoPsicologico(feliz)<-muda(E).
+estimulo(inquestionavel):personalidade(apressado)&estadoPsicologico(zangado)<-muda(E).
+estimulo(inquestionavel):personalidade(apressado)&estadoPsicologico(apreensivo)<-muda(E).
+estimulo(inquestionavel):personalidade(apressado)&estadoPsicologico(lisonjeado)<-muda(E).
+estimulo(inquestionavel):personalidade(apressado)&estadoPsicologico(compreensivo)<-muda(E).

+started <- startCivil.