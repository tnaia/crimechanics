/*
A ideia é que o protocolo seja fácil de alterar.
 */

// Envio de mensagem.

vector<unsigned int> mensagem; // vetor de inteiros sem sinal

// Suponhamos que vou mandar a mensagem "estimulaAgente (7, fala-amigavel)".
// ou seja, vou estimular o agente 7 com uma fala amigável. 
// Ela tem dois parâmetros.
// Vou montar a mensagem e então enviá-la.

// número de elementos da mensagem (nome da mensagem + parâmetros).
// não inclui o número de números enviados.
mensagem.pushback( 3 ); 

unsigned int aux;

// Descobre qual a linha em que ocorre o nome da mensagem que quero enviar
aux = numero_linha( "estimulaAgente", "mensagens.txt" );
mensagem.pushback( aux );

// agente que quero estimular
mensagem.pushback( 7 );

aux = numero_linha( "fala-amigavel", "estimulos.txt" );
mensagem.pushback( aux );

// agora que a mensagem está montada, é só enviar

for( int i = 0; i < mensagem.size(); ++i )
  envia_numero( mensagem[ i ] );
		
