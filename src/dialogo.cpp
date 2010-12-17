#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <stack>
#include <utility>
#include <set>

#include "dialogo.h"
using namespace std;
unsigned int numck = 0;
Dialogo::Dialogo ( string nome_arq_script ) {
  int i = 0;
  ++i;
}

enum tipo_token { LANGLE, RANGLE, SLASH,
		  SIMPLE_WORD, TEXT,
		  EQUALS, 
		  SWITCHON, SWITCHOFF, 
		  ONLY, 
		  GOTO,
		  COLOR,
		  LABEL,
		  OPTS, OP,
		  WAIT,
		  BACKGROUND, BACKGROUND_COLOR,
		  FADEIN, FADEOUT,
		  MUSIC };

struct Token{
  tipo_token tipo;
  string valor;
  Token() {;};
};

typedef void (*ptr2func)(string origem, struct Token &t, string destino, void * data);
typedef void (*ptr2funcSemToken)(string origem, string destino, void * data);

class SimuladorAutomato {
public:
  SimuladorAutomato() {};
  void add_transition( string origem, tipo_token tipo, string destino, ptr2func f );
  void add_auto_transition( string origem, string destino, ptr2funcSemToken f );
  bool simula_automato( string estado_inicial, vector<struct Token> v, void * data );
  void set_as_accepting( string estado );
private:
  vector<string> estados;
  map< string, map< tipo_token, pair<string, ptr2func> > > transicoes;
  map< string, pair<string, ptr2funcSemToken> > auto_transicoes;
  set<string> aceitacao;  
};

void SimuladorAutomato::set_as_accepting( string estado ) {
  aceitacao.insert( estado );
}

void SimuladorAutomato::add_auto_transition( string origem, string destino, ptr2funcSemToken f )
{
  auto_transicoes[origem] = make_pair( destino, f );
}

bool SimuladorAutomato::simula_automato( string estado_inicial, vector<struct Token> v, void * data )
{
  stack<string> estado_atual;
  unsigned int num_token = 0 ;
  estado_atual.push( estado_inicial );
  // se tem autotransição faz ela primeiro.
 
 
  if( auto_transicoes.find( estado_atual.top() ) != auto_transicoes.end() )
    {
      // keep current state on the stack and stack next onto it (the destination from an state with autotransition must be unique).
      estado_atual.push( estado_inicial );
    }
  else if ( ( transicoes.find( estado_atual.top() ) != transicoes.end() )
	    && ( transicoes[ estado_atual.top() ].find( v[ num_token ].tipo ) != transicoes[estado_atual.top()].end() ) )
    {
      string destino = transicoes[ estado_atual.top() ][ v[ num_token ].tipo ].first;
      transicoes[ estado_atual.top() ][ v[ num_token ].tipo ].second
	( estado_atual.top(), v[ num_token ], destino, data );
      estado_atual.pop();
      estado_atual.push( destino );
      ++num_token;
    }
  else if( aceitacao.find( estado_atual.top() )  != aceitacao.end() )
    {
      estado_atual.pop();
      string origem = estado_atual.top();
      string destino = auto_transicoes[ estado_atual.top() ].first;
      ptr2funcSemToken f = auto_transicoes[ estado_atual.top() ].second;
      f ( origem, destino, data );
    }
  return true;
}

void SimuladorAutomato::add_transition( string origem, tipo_token tipo, string destino, ptr2func f )
{
  transicoes[ origem ][ tipo ] = make_pair( destino, f );
}

bool read_simple_word( ifstream &in, struct Token &t )
{
  map<string, tipo_token> tipos;
  tipos[ "switchon" ] = SWITCHON;
  tipos[ "switchoff" ] = SWITCHOFF;
  tipos[ "only" ] = ONLY;
  tipos[ "opts" ] = OPTS;
  tipos[ "op" ] = OP;
  tipos[ "goto" ] = GOTO;
  tipos[ "color" ] = COLOR;
  tipos[ "label" ] = LABEL;
  tipos[ "wait" ] = WAIT;
  tipos[ "background" ] = BACKGROUND;
  tipos[ "fadein" ] = FADEIN;
  tipos[ "fadeout" ] = FADEOUT;
  tipos[ "music" ] = MUSIC;
  tipos[ "background-color" ] = BACKGROUND_COLOR;
  string already_read = "";
  char c;
  c = in.get();

  while( in.good() )
    {
      if( ( 'a' <= c && c <= 'z' ) 
	  || ( 'A' <= c && c <= 'Z' ) 
	  || ( '0' <= c && c <= '9' )
	  || c == '-' || c == '_' || c == '.' )
	{
	  already_read += c;
	  c = in.get();
	}
      else
	{
	  in.unget();
	  break;
	}
    }
  //cout << "pequena palavra " << already_read << endl; 
  if( already_read.length() > 0 )
    {
      vector<string> keywords;
      keywords.push_back( "switchon" );
      keywords.push_back( "switchoff" );
      keywords.push_back( "only" );
      keywords.push_back( "opts" );
      keywords.push_back( "op" );
      keywords.push_back( "goto" );
      keywords.push_back( "color" );
      keywords.push_back( "label" );
      keywords.push_back( "wait" );
      keywords.push_back( "background" );
      keywords.push_back( "fadein" );
      keywords.push_back( "fadeout" );   
      keywords.push_back( "music" );
      keywords.push_back( "background-color" );
      //cout<<"\t\t\t"<<already_read<<endl;
      unsigned int pos = 0;
      while( keywords.size() > 0  && pos < already_read.length() )
	{
	  /*
	  cout<<"opções"<<endl;
	  for( unsigned int j = 0; j < keywords.size(); ++j )
	    cout<<keywords[j]<<endl;
	      cout<<"---"<<endl;
	  */
	  for( unsigned int i = 0; i < keywords.size(); ++i )
	    if( keywords[ i ].length() <= pos 
		|| ( 'A' > keywords[i][ pos ] 
		     &&  keywords[i][ pos ] > 'Z'
		     &&  keywords[ i ][ pos ] != already_read[ pos ] )
		|| ( 'A' <= already_read [ pos ]
		     && already_read [ pos ] <= 'Z' 
		     && keywords[ i ][ pos ] + ( 'A' - 'a' ) != already_read[ pos ] ) )
	      keywords.erase( keywords.begin() + i );
	  
	  ++pos;
	}
      
      if( keywords.size() == 1 && keywords[0].length() == already_read.length())
	{
	  t.valor = "";
	  t.tipo = tipos[ keywords[ 0 ] ];
	}
      else
	{
	  t.valor = already_read;
	  t.tipo = SIMPLE_WORD;
	}
      return 1;
    }
  else
    {
      return false;
    }



  /*  char c;
  c = in.get();
  while( in.good() && ( c == ' ' || c == '\t' || c == '\n' ) )
    c = in.get();

    if( in.good() )
      switch( c )
	{
	case 's':
	case 'S':
	  int pos = 1;
	  string word1 = "switchon";
	  string word2 = "switchoff";
	  while (pos < word1.length() ||
	  break;
	case 'o':
	case 'O':
	  break;
	case 'g':
	case 'G':
	  break;
	case 'c':
	case 'C':
	  break;
	case 'l':
	case 'L':
	  break;
	case 'w':
	case 'W':
	  break;
	case 'b':
	case 'B':
	  break;
	case 'f':
	case 'F':
	  break;
	default:
	  in.unget();
	  return false;
	  }*/
    return true;
}

int get_token( struct Token & t, ifstream &in )
{
  static bool inside_angles = false;
  char c;

  if( !in.good() )
    return 0;

  bool achou = false;
  c = in.get();

  while( in.good() && !achou )
    {
      //cout<<"entrei no while"<< endl;
      while( in.good() && ( c == ' ' || c == '\t' || c == '\n' ) )
	c = in.get();

      if( ! in.good() )
	break;
  
      switch( c )
	{
	case '<':
	  if ( in.get() == '!' )
	    {
	      //cout << "comentário"<< endl;
	      do {
		c = in.get();
	      } while( in.good() && c != '<' );
	      if( c == '<' )
		{
		  in.unget();
		  c = in.get();
		}
	      continue; // <<<<<< olha pra esse cara aqui
	    }
	  else 
	    {
	      in.unget();
	      //cout<<"langle"<< endl;
	      t.tipo = LANGLE;
	      t.valor = "";
	      achou = true;
	      inside_angles = true;
	      break;
	    }
	case '>':
	  //cout << "rangle" << endl;
	  t.tipo = RANGLE;
	  t.valor = "";
	  achou = true;
	  inside_angles = false;
	  break;
	case '/':
	  //cout << "slash" << endl;
	  t.tipo = SLASH;
	  t.valor = "";
	  achou = true;
	  break;
	case '=':
	  //cout << "equals" << endl;
	  t.tipo = EQUALS;
	  t.valor = "";
	  achou = true;
	  break;
	default:
	  //cout << "default" << endl;
	  in.unget();
	  if( inside_angles && read_simple_word( in, t ) )
	    {
	      achou = true;
	      break;		
	    } 
	  else if( inside_angles )
	    {
	      cerr << "! expressão inválida no diálogo: " 
		   << t.valor 
		   << endl 
		   << "  Abortando" << endl ;
	    }
	  else 
	    {
	      t.tipo = TEXT;
	      c = in.get();
	      while( in.good() && c != '<' )
		{
		  t.valor += c;
		  c = in.get();
		}
	      // remove brancos ao fim
	      unsigned int f = t.valor.length();
	      while( f > 1 
		     && ( t.valor[ f -1 ] == ' '  
			  || t.valor[ f -1 ] == '\n' 
			  || t.valor[ f -1 ] == '\t' ) )
		     --f;
	      t.valor = t.valor.substr( 0, f );
	      if( c == '<' )
		in.unget();
	      achou = true;
	    }
	}
    }
  if( achou )
    return 1;
  return 0;
}

vector<struct Token> * tokenize_file( string nome_arq )
{
  vector<struct Token> * v = new vector<Token>();
  struct Token t;
  ifstream in;
  in.open( nome_arq.c_str(), ios_base::in );

  while( get_token( t, in ) == 1 )
    {
      v->push_back( t );
    }

  in.close();

  return v;
}


void fooComToken( string, struct Token &, string, void * )
{
  cout << "chamada fooComToken" << endl;
}

void fooSemToken( string, string, void * )
{
  cout << "chamada fooSemToken" << endl;
}

int main(int argc, char ** argv ) {
  if( argc != 2 )
    {
      cerr<< "2 argumentos, moron!\n"<<endl;
      return 1;
    }

  vector<struct Token> * v = tokenize_file( argv[1] );

  map<tipo_token, string> tipos;
  tipos[ LANGLE ] = "langle";
  tipos[ RANGLE ] = "rangle";
  tipos[ SLASH ] = "slash";
  tipos[ SIMPLE_WORD ] = "simple word...";
  tipos[ TEXT ] = "text...";
  tipos[ EQUALS ] = "equals";
  tipos[ SWITCHON ] = "switchOn";
  tipos[ SWITCHOFF ] = "switchOff";
  tipos[ ONLY ] = "only";
  tipos[ GOTO ] = "goto";
  tipos[ COLOR ] = "color";
  tipos[ LABEL ] = "label";
  tipos[ OPTS ] = "opts";
  tipos[ OP ] = "op";
  tipos[ WAIT ] = "wait";
  tipos[ BACKGROUND ] = "background";
  tipos[ FADEIN ] = "fadeIn";
  tipos[ FADEOUT ] = "fadeOut";
  tipos[ MUSIC ] = "music";
  tipos[ BACKGROUND_COLOR ] = "background-color";
  for( unsigned int i = 0; i < v->size(); ++i )
    cout << tipos[ (*v)[i].tipo ] << "\t\t" << (*v)[i].valor << endl;

  SimuladorAutomato sm;
  sm.add_auto_transition( "009", "010", fooSemToken );

  sm.add_transition( "000", LANGLE, "001", fooComToken );

  sm.add_transition( "001", SWITCHON, "002", fooComToken );
  sm.add_transition( "001", SWITCHOFF, "002", fooComToken );
  sm.add_transition( "001", ONLY, "002", fooComToken );
  sm.add_transition( "001", SIMPLE_WORD, "003", fooComToken );
  sm.add_transition( "001", RANGLE, "004", fooComToken );
  sm.add_transition( "001", OPTS, "005", fooComToken );
  sm.add_transition( "001", BACKGROUND, "006", fooComToken );
  sm.add_transition( "001", LABEL, "006", fooComToken );
  sm.add_transition( "001", FADEIN, "006", fooComToken );
  sm.add_transition( "001", GOTO, "006", fooComToken );
  sm.add_transition( "001", COLOR, "006", fooComToken );
  sm.add_transition( "001", WAIT, "006", fooComToken );
  sm.add_transition( "001", BACKGROUND_COLOR, "006", fooComToken );
  sm.add_transition( "001", FADEIN, "006", fooComToken );
  sm.add_transition( "001", SLASH, "007", fooComToken );

  sm.add_transition( "002", EQUALS, "008", fooComToken );

  sm.add_transition( "003", SWITCHON, "002", fooComToken );
  sm.add_transition( "003", SWITCHOFF, "002", fooComToken );
  sm.add_transition( "003", ONLY, "002", fooComToken );
  sm.add_transition( "003", SIMPLE_WORD, "003", fooComToken );
  sm.add_transition( "003", RANGLE, "004", fooComToken );

  sm.add_transition( "004", TEXT, "000", fooComToken );

  sm.add_transition( "005", RANGLE, "009", fooComToken );

  sm.add_transition( "010", LANGLE, "011", fooComToken );

  sm.add_transition( "011", SLASH, "012", fooComToken );

  sm.add_transition( "012", OPTS, "007", fooComToken );

  sm.add_transition( "007", RANGLE, "000", fooComToken );

  sm.add_transition( "008", SIMPLE_WORD, "003", fooComToken );

  sm.add_transition( "006", EQUALS, "013", fooComToken );

  sm.add_transition( "013", SIMPLE_WORD, "014", fooComToken );

  sm.add_transition( "014", SIMPLE_WORD, "014", fooComToken );
  sm.add_transition( "014", SWITCHON, "015", fooComToken );
  sm.add_transition( "014", SWITCHOFF, "015", fooComToken );
  sm.add_transition( "014", ONLY, "015", fooComToken );
  sm.add_transition( "014", RANGLE, "016", fooComToken );

  sm.add_transition( "016", TEXT, "010", fooComToken );


  /*
  sm.add_transition( "001", RANGLE, "000", fooComToken );
  sm.add_transition( "001", SIMPLE_WORD, "001", fooComToken );
  sm.add_transition( "001", SWITCHON, "002", fooComToken ); 
  sm.add_transition( "001", SWITCHOFF, "002", fooComToken ); 
  sm.add_transition( "001", ONLY, "002", fooComToken ); 
  sm.add_transition( "001", OPTS, "004", fooComToken );
  sm.add_transition( "001", BACKGROUND, "010", fooComToken );
  sm.add_transition( "001", LABEL, "010", fooComToken );
  sm.add_transition( "001", GOTO, "010", fooComToken );
  sm.add_transition( "001", COLOR, "010", fooComToken );
  sm.add_transition( "001", WAIT, "010", fooComToken );
  sm.add_transition( "001", BACKGROUND_COLOR, "010", fooComToken );
  sm.add_transition( "001", FADEIN, "010", fooComToken );
  sm.add_transition( "001", FADEOUT, "010", fooComToken );

  sm.add_transition( "002", EQUALS, "003", fooComToken );

  sm.add_transition( "003", SIMPLE_WORD, "001", fooComToken );
  
  sm.add_transition( "004", RANGLE, "005", fooComToken );

  sm.add_transition( "006", LANGLE, "007", fooComToken );

  sm.add_transition( "007", SLASH, "008", fooComToken );

  sm.add_transition( "008", OPTS, "009", fooComToken );

  sm.add_transition( "009", RANGLE, "000", fooComToken );

  sm.add_transition( "010", EQUALS, "011", fooComToken );

  sm.add_transition( "011", SIMPLE_WORD, "012", fooComToken );

  sm.add_transition( "012", SIMPLE_WORD, "012", fooComToken );
  sm.add_transition( "012", SWITCHON, "013", fooComToken );
  sm.add_transition( "012", SWITCHOFF, "013", fooComToken );
  sm.add_transition( "012", ONLY, "013", fooComToken );
  sm.add_transition( "012", RANGLE, "014", fooComToken );

  sm.add_transition( "013", EQUALS, "011", fooComToken );
  */
  sm.set_as_accepting( "000" );
  sm.set_as_accepting( "016" );


  delete v;
  return 0;
}
