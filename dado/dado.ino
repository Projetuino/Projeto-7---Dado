//Mapeamento dos pinos do display na
//sequencia {a, b, c, d, e, f, g, DP}
const int pinos[8] = {4, 5, 10, 9, 8, 3, 2, 11};
const int numeros[10][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1, 0},
  {1, 1, 1, 1, 0, 0, 1, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1, 0},
  {1, 0, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 0, 1, 1, 0}
};
const int botao = 13;
int numero = 0;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(pinos[i], OUTPUT);
  }
  pinMode(botao, INPUT);
  randomSeed(A0);
}

void loop() {
  if (digitalRead(botao) == 1) {
    numero = random(1, 7);
    roleta();
  }
  mostrarNumero(numero);
}

void roleta() {
  digitalWrite(pinos[6], LOW);
  for (int i = 0; i <= 4; i++) {
    for (int s = 0; s <= 5; s++) {
      digitalWrite(pinos[s], HIGH);
      delay(25);
      digitalWrite(pinos[s], LOW);
    }
  }
}

void mostrarNumero(int num) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(pinos[i], numeros[num][i]);
  }
}
