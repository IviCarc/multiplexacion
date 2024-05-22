int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 8;
int G = 7;

int pins[7] = {A, B, C, D, E, F, G};

int btnA = 9;
int btnB = 10;

int transistorA = 11;
int transistorB = 12;

int contador = 0;

int frecuencia = 50;

void setup()
{
  pinMode(btnA, INPUT);
  pinMode(btnB, INPUT);
  pinMode(transistorA, OUTPUT);
  pinMode(transistorB, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

// Cada fila de la matriz o array de arrays, representa un pin / led del display.
// Cada columna de la matriz, representa un digito en el display.
// Se lee, de izquierda a derecha, el valor que toma cada LED en el display, por dígito.
// Vease, en la segunda fila, el segundo elemento es un 1 (keys[1][1]), esto es, el LED B del display debe encenderse para mostrar el digito 1.

int keys[7][10] = {

 //0  1  2  3  4  5  6  7  8  9  
  {1, 0, 1, 1, 0, 1, 1, 1, 1, 1}, // A
  {1, 1, 1, 1, 1, 0, 0, 1, 1, 1}, // B
  {1, 1, 0, 1, 1, 1, 1, 1, 1, 1}, // C
  {1, 0, 1, 1, 0, 1, 1, 0, 1, 1}, // D
  {1, 0, 1, 0, 0, 0, 1, 0, 1, 0}, // E
  {1, 0, 0, 0, 1, 1, 1, 0, 1, 1}, // F
  {0, 0, 1, 1, 1, 1, 1, 0, 1, 1}  // G
};


void display(int num) {
  // Calcula la decena y la unidad para mostrarlas en el respectivo display
  int decena = (num - (num % 10)) / 10;
  int unidad = num - decena * 10;

  digitalWrite(transistorA, HIGH);
  digitalWrite(transistorB, LOW);

  // Enciende los LEDs correspondientes a la decena
  for (int i = 0; i < 7; i++) {
    digitalWrite(pins[i], keys[i][decena]);
  }

  delay(frecuencia);

  digitalWrite(transistorA, LOW);
  digitalWrite(transistorB, HIGH);
  
  // Enciende los LEDs correspondientes a la unidad

  for (int i = 0; i < 7; i++) {
    digitalWrite(pins[i], keys[i][unidad]);
  }

  delay(frecuencia);
}

void loop()
{
  if (digitalRead(btnA) == HIGH) {

    if (contador != 0 && contador != 20) {
        contador ++;
    }
    
    if (contador == 0) contador = 10;

  }

  if (digitalRead(btnB) == HIGH) {
    if (contador != 10) {
        contador --;
    }
  }
  
  display(contador);
}