// Agent a110 in project Agents_tcc.mas2j


/* Initial beliefs and rules */
started.
/* Initial goals */

/* Plans */
/*estimulo agmigavel*/

+estimulo(falaAmigavel):personalidade(rabugento)&estadoPsicologico(feliz)<-atualizarP(simpatico);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(rabugento)&estadoPsicologico(zangado)<-ataulizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(rabugento)&estadoPsicologico(apreensivo)<-ataulizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-ataulizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(rabugento)&estadoPsicologico(compreensivo)<-ataulizarEP(compreensivo);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(simpatico)&estadoPsicologico(feliz)<-removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(simpatico)&estadoPsicologico(zangado)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(simpatico)&estadoPsicologico(apreensivo)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(simpatico)&estadoPsicologico(compreensivo)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(educado)&estadoPsicologico(feliz)<-removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(educado)&estadoPsicologico(zangado)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(educado)&estadoPsicologico(apreensivo)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(educado)&estadoPsicologico(lisonjeado)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(educado)&estadoPsicologico(compreensivo)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(grosseiro)&estadoPsicologico(feliz)<-atualizarP(educado);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(grosseiro)&estadoPsicologico(zangado)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(apressado)&estadoPsicologico(feliz)<-removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(apressado)&estadoPsicologico(zangado)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(apressado)&estadoPsicologico(apreensivo)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(apressado)&estadoPsicologico(lisonjeado)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).
+estimulo(falaAmigavel):personalidade(apressado)&estadoPsicologico(compreensivo)<-atualizarEP(feliz);removerEstimulo(falaAmigavel).

/*estimulo elogio*/
+estimulo(elogio):personalidade(rabugento)&estadoPsicologico(feliz)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(rabugento)&estadoPsicologico(zangado)<-removerEstimulo(elogio).
+estimulo(elogio):personalidade(rabugento)&estadoPsicologico(apreensivo)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-atualizarEP(zangado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(rabugento)&estadoPsicologico(compreensivo)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(simpatico)&estadoPsicologico(feliz)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(simpatico)&estadoPsicologico(zangado)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(simpatico)&estadoPsicologico(apreensivo)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-removerEstimulo(elogio).
+estimulo(elogio):personalidade(simpatico)&estadoPsicologico(compreensivo)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(educado)&estadoPsicologico(feliz)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(educado)&estadoPsicologico(zangado)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(educado)&estadoPsicologico(apreensivo)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(educado)&estadoPsicologico(lisonjeado)<-removerEstimulo(elogio).
+estimulo(elogio):personalidade(educado)&estadoPsicologico(compreensivo)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(grosseiro)&estadoPsicologico(feliz)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(grosseiro)&estadoPsicologico(zangado)<-removerEstimulo(elogio).
+estimulo(elogio):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-atualizarEP(zangado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-atualizarEP(zangado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-removerEstimulo(elogio).
+estimulo(elogio):personalidade(apressado)&estadoPsicologico(feliz)<-atualizarEP(lisonjeado);removerEstimulo(elogio).
+estimulo(elogio):personalidade(apressado)&estadoPsicologico(zangado)<-removerEstimulo(elogio).
+estimulo(elogio):personalidade(apressado)&estadoPsicologico(apreensivo)<-removerEstimulo(elogio).
+estimulo(elogio):personalidade(apressado)&estadoPsicologico(lisonjeado)<-removerEstimulo(elogio).
+estimulo(elogio):personalidade(apressado)&estadoPsicologico(compreensivo)<-atualizarEP(lisonjeado);removerEstimulo(elogio).

/*estimulo insulto*/
+estimulo(insulto):personalidade(rabugento)&estadoPsicologico(feliz)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(rabugento)&estadoPsicologico(zangado)<-removerEstimulo(insulto).
+estimulo(insulto):personalidade(rabugento)&estadoPsicologico(apreensivo)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(rabugento)&estadoPsicologico(compreensivo)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(simpatico)&estadoPsicologico(feliz)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(simpatico)&estadoPsicologico(zangado)<-atualizarP(grosseiro);removerEstimulo(insulto).
+estimulo(insulto):personalidade(simpatico)&estadoPsicologico(apreensivo)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(simpatico)&estadoPsicologico(compreensivo)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(educado)&estadoPsicologico(feliz)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(educado)&estadoPsicologico(zangado)<-atualizarP(grosseiro);removerEstimulo(insulto).
+estimulo(insulto):personalidade(educado)&estadoPsicologico(apreensivo)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(educado)&estadoPsicologico(lisonjeado)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(educado)&estadoPsicologico(compreensivo)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(grosseiro)&estadoPsicologico(feliz)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(grosseiro)&estadoPsicologico(zangado)<-removerEstimulo(insulto).
+estimulo(insulto):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(apressado)&estadoPsicologico(feliz)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(apressado)&estadoPsicologico(zangado)<-atulizarP(grosseiro);removerEstimulo(insulto).
+estimulo(insulto):personalidade(apressado)&estadoPsicologico(apreensivo)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(apressado)&estadoPsicologico(lisonjeado)<-atualizarEP(zangado);removerEstimulo(insulto).
+estimulo(insulto):personalidade(apressado)&estadoPsicologico(compreensivo)<-atualizarEP(zangado);removerEstimulo(insulto).

/*estimulo fala-timida*/
+estimulo(falaTimida):personalidade(rabugento)&estadoPsicologico(feliz)<-atualizarEP(zangado);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(rabugento)&estadoPsicologico(zangado)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(rabugento)&estadoPsicologico(apreensivo)<-atualizarEP(zangado);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(rabugento)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(simpatico)&estadoPsicologico(feliz)<-removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(simpatico)&estadoPsicologico(zangado)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(simpatico)&estadoPsicologico(apreensivo)<-removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(simpatico)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(educado)&estadoPsicologico(feliz)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(educado)&estadoPsicologico(zangado)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(educado)&estadoPsicologico(apreensivo)<-atualizarP(apressado);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(educado)&estadoPsicologico(lisonjeado)<-muda(E);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(educado)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(grosseiro)&estadoPsicologico(feliz)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(grosseiro)&estadoPsicologico(zangado)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(apressado)&estadoPsicologico(feliz)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(apressado)&estadoPsicologico(zangado)<-removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(apressado)&estadoPsicologico(apreensivo)<-removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(apressado)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).
+estimulo(falaTimida):personalidade(apressado)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(falaTimida).

/*estimulo inquisitivo*/
+estimulo(inquisitivo):personalidade(rabugento)&estadoPsicologico(feliz)<-atualizarEP(zangado);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(rabugento)&estadoPsicologico(zangado)<-removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(rabugento)&estadoPsicologico(apreensivo)<-atualizarEP(zangado);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(rabugento)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(simpatico)&estadoPsicologico(feliz)<-atualizarEP(zangado);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(simpatico)&estadoPsicologico(zangado)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(simpatico)&estadoPsicologico(apreensivo)<-atualizarP(rabugento);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(simpatico)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(educado)&estadoPsicologico(feliz)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(educado)&estadoPsicologico(zangado)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(educado)&estadoPsicologico(apreensivo)<-atualizarEP(zangado);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(educado)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(educado)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(grosseiro)&estadoPsicologico(feliz)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(grosseiro)&estadoPsicologico(zangado)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-atualizarEP(zangado);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(apressado)&estadoPsicologico(feliz)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(apressado)&estadoPsicologico(zangado)<-removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(apressado)&estadoPsicologico(apreensivo)<-removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(apressado)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).
+estimulo(inquisitivo):personalidade(apressado)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(inquisitivo).

/*estimulo suspeito*/
+estimulo(suspeito):personalidade(rabugento)&estadoPsicologico(feliz)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(rabugento)&estadoPsicologico(zangado)<-removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(rabugento)&estadoPsicologico(apreensivo)<-removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(rabugento)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(simpatico)&estadoPsicologico(feliz)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(simpatico)&estadoPsicologico(zangado)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(simpatico)&estadoPsicologico(apreensivo)<-atualizarP(grosseiro);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(simpatico)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(educado)&estadoPsicologico(feliz)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(educado)&estadoPsicologico(zangado)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(educado)&estadoPsicologico(apreensivo)<-atualizarP(grosseiro);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(educado)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(educado)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(grosseiro)&estadoPsicologico(feliz)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(grosseiro)&estadoPsicologico(zangado)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(apressado)&estadoPsicologico(feliz)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(apressado)&estadoPsicologico(zangado)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(apressado)&estadoPsicologico(apreensivo)<-removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(apressado)&estadoPsicologico(lisonjeado)<-atualizarEP(apreensivo);removerEstimulo(suspeito).
+estimulo(suspeito):personalidade(apressado)&estadoPsicologico(compreensivo)<-atualizarEP(apreensivo);removerEstimulo(suspeito).


/*estimulo inquestionavel*/
+estimulo(inquestionavel):personalidade(rabugento)&estadoPsicologico(feliz)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(rabugento)&estadoPsicologico(zangado)<-removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(rabugento)&estadoPsicologico(apreensivo)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(rabugento)&estadoPsicologico(lisonjeado)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(rabugento)&estadoPsicologico(compreensivo)<-removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(simpatico)&estadoPsicologico(feliz)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(simpatico)&estadoPsicologico(zangado)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(simpatico)&estadoPsicologico(apreensivo)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(simpatico)&estadoPsicologico(lisonjeado)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(simpatico)&estadoPsicologico(compreensivo)<-removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(educado)&estadoPsicologico(feliz)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(educado)&estadoPsicologico(zangado)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(educado)&estadoPsicologico(apreensivo)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(educado)&estadoPsicologico(lisonjeado)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(educado)&estadoPsicologico(compreensivo)<-removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(grosseiro)&estadoPsicologico(feliz)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(grosseiro)&estadoPsicologico(zangado)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(grosseiro)&estadoPsicologico(apreensivo)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(grosseiro)&estadoPsicologico(compreensivo)<-atualizarP(simpatico);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(apressado)&estadoPsicologico(feliz)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(apressado)&estadoPsicologico(zangado)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(apressado)&estadoPsicologico(apreensivo)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(apressado)&estadoPsicologico(lisonjeado)<-atualizarEP(compreensivo);removerEstimulo(inquestionavel).
+estimulo(inquestionavel):personalidade(apressado)&estadoPsicologico(compreensivo)<-atualizarP(simpatico);removerEstimulo(inquestionavel).

+started <- startCivil.

+responder:personalidade(rabugento)&estadoPsicologico(feliz)<-resposta(rabugento,feliz).
+responder:personalidade(rabugento)&estadoPsicologico(zangado)<-resposta(simpatico).
+responder:personalidade(rabugento)&estadoPsicologico(apreensivo)<-resposta(simpatico).
+responder:personalidade(rabugento)&estadoPsicologico(lisonjeado)<-resposta(simpatico).
+responder:personalidade(rabugento)&estadoPsicologico(compreensivo)<-resposta(simpatico).
+responder:personalidade(simpatico)&estadoPsicologico(feliz)<-resposta(simpatico).
+responder:personalidade(simpatico)&estadoPsicologico(zangado)<-resposta(simpatico).
+responder:personalidade(simpatico)&estadoPsicologico(apreensivo)<-resposta(simpatico).
+responder:personalidade(simpatico)&estadoPsicologico(lisonjeado)<-resposta(simpatico).
+responder:personalidade(simpatico)&estadoPsicologico(compreensivo)<-resposta(simpatico).
+responder:personalidade(educado)&estadoPsicologico(feliz)<-resposta(simpatico).
+responder:personalidade(educado)&estadoPsicologico(zangado)<-resposta(simpatico).
+responder:personalidade(educado)&estadoPsicologico(apreensivo)<-resposta(simpatico).
+responder:personalidade(educado)&estadoPsicologico(lisonjeado)<-resposta(simpatico).
+responder:personalidade(educado)&estadoPsicologico(compreensivo)<-resposta(simpatico).
+responder:personalidade(grosseiro)&estadoPsicologico(feliz)<-resposta(simpatico).
+responder:personalidade(grosseiro)&estadoPsicologico(zangado)<-resposta(simpatico).
+responder:personalidade(grosseiro)&estadoPsicologico(apreensivo)<-resposta(simpatico).
+responder:personalidade(grosseiro)&estadoPsicologico(lisonjeado)<-resposta(simpatico).
+responder:personalidade(grosseiro)&estadoPsicologico(compreensivo)<-resposta(simpatico).
+responder:personalidade(apressado)&estadoPsicologico(feliz)<-resposta(simpatico).
+responder:personalidade(apressado)&estadoPsicologico(zangado)<-resposta(simpatico).
+responder:personalidade(apressado)&estadoPsicologico(apreensivo)<-resposta(simpatico).
+responder:personalidade(apressado)&estadoPsicologico(lisonjeado)<-resposta(simpatico).
+responder:personalidade(apressado)&estadoPsicologico(compreensivo)<-resposta(simpatico).

