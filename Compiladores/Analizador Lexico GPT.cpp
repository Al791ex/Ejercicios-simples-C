#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Enumeraci�n para representar los tipos de tokens
enum TipoToken {
  NUMERO,
  OPERADOR,
  PARENTESIS_IZQ,
  PARENTESIS_DER
};

// Estructura para representar un token
struct Token {
  TipoToken tipo;
  string valor;
};

// Funci�n que realiza el an�lisis l�xico
vector<Token> analizarLexico(const string& expresion) {
  vector<Token> tokens;
  int longitud = expresion.length();

  for (int i = 0; i < longitud; i++) {
    char c = expresion[i];

    if (c == ' ') {
      continue;  // Ignorar espacios en blanco
    } else if (isdigit(c)) {
      // Analizar un n�mero
      string numero;
      numero += c;

      // Leer los d�gitos siguientes
      while (i + 1 < longitud && isdigit(expresion[i + 1])) {
        i++;
        numero += expresion[i];
      }

      tokens.push_back({NUMERO, numero});
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      // Analizar un operador
      tokens.push_back({OPERADOR, string(1, c)});
    } else if (c == '(') {
      // Analizar par�ntesis izquierdo
      tokens.push_back({PARENTESIS_IZQ, string(1, c)});
    } else if (c == ')') {
      // Analizar par�ntesis derecho
      tokens.push_back({PARENTESIS_DER, string(1, c)});
    } else {
      // Car�cter no v�lido
      cout << "Error: Car�cter no v�lido encontrado" << endl;
      break;
    }
  }

  return tokens;
}

// Funci�n auxiliar para imprimir los tokens
void imprimirTokens(const vector<Token>& tokens) {
  for (const Token& token : tokens) {
    string tipo;

    switch (token.tipo) {
      case NUMERO:
        tipo = "N�mero";
        break;
      case OPERADOR:
        tipo = "Operador";
        break;
      case PARENTESIS_IZQ:
        tipo = "Par�ntesis Izquierdo";
        break;
      case PARENTESIS_DER:
        tipo = "Par�ntesis Derecho";
        break;
    }

    cout << "Tipo: " << tipo << ", Valor: " << token.valor << endl;
  }
}

int main() {
  string expresion;
  cout << "Ingrese una expresi�n matem�tica: ";
  getline(cin, expresion);

  vector<Token> tokens = analizarLexico(expresion);
  imprimirTokens(tokens);

  return 0;
}

