#include <iostream>
#include <vector>
#include <fstream>

#include "dialogo.h"
using namespace std;

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
		  BACKGROUND,
		  FADEIN, FADEOUT };

struct Token{
  tipo_token tipo;
  string valor;
  Token() {;};
};

bool read_simple_word( ifstream &in, string &s )
{
  char c;
  c = in.get();
    if( in.good() )
      switch( c )
	{
	case 's':
	case 'S':
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
case  
}

int get_token( struct Token & t, ifstream &in )
{
  static bool inside_angles = false;
  char c;

  if( !in.good() )
    return 0;

  bool achou = false;
  c = in.get();

  while( in.good() )
    {
      
      while( in.good() && ( c == ' ' || c == '\t' || c == '\n' ) )
	c = in.get();
      
      if( ! in.good() )
	break;
      
      switch( c )
	{
	case '<':
	  if ( in.good() && '!' == in.get() )
	    {
	      do {
		c = in.get();
	      } while( in.good() && c != '<' );
	      if( c == '<' )
		in.unget();
	      continue;
	    } 
	  else 
	    {
	      in.unget();
	      t.tipo = LANGLE;
	      t.valor = "";
	      achou = true;
	      inside_angles = true;
	      break;
	    }
	case '>':
	  t.tipo = RANGLE;
	  t.valor = "";
	  achou = true;
	  inside_angles = false;
	  break;
	case '/':
	  t.tipo = SLASH;
	  t.valor = "";
	  achou = true;
	  break;
	case '=':
	  t.tipo = EQUALS;
	  t.valor = "";
	  achou = true;
	  break;
	default:
	  if( inside_angles && read_simple_word( in, t.valor ) )
	    {
	      t.tipo = SIMPLE_WORD;
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
	      valor += c;
	      c = in.get();
	      while( in.good() && c != '<' )
		{
		  valor += c;
		  c = in.get();
		}
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
      //cout << t.valor << " " << (*v)[v->size() -1].valor << endl;
    }

  in.close();

  return v;
}

int main() {
  cout<< "Oi"<< endl;
  vector<struct Token> * v = tokenize_file( "dialogo.cpp" );
  
  for( unsigned int i = 0; i < v->size(); ++i )
    cout << (*v)[i].valor;
  delete v;
  return 0;
}
