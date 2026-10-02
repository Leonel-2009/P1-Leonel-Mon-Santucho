#define bot 2
#define bot2 3
#define bot3 4
#define Pie 8

int Botton;
int Botton2;
int Botton3;

// tema1
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Db6 1245
#define D6 1175
#define Cb6 1109
#define B5 988

// tema2
#define D6 1175
#define B5 988
#define A5 880
#define C6 1047
#define Cb6 1109

//tema3
#define Db6 1245
#define C6 1047
#define Ab5 932
#define Cb6 1109

const int tema1[5][3] = {
 {Db6, 136, 136},
 {D6, 136, 273},
 {Cb6, 136, 136},
 {B5, 273, 136},
 {Db6, 136, 0},
};

const int tema2[5][3] = {
 {D6, 273, 136},
 {B5, 136, 136},
 {A5, 136, 136},
 {C6, 136, 273},
 {Cb6, 409, 0},
};

const int tema3[6][3] = {
 {Db6, 955, 136},
 {C6, 273, 273},
 {Ab5, 136, 0},
 {Cb6, 136, 0},
 {Db6, 136, 136},
 {C6, 136, 0},
};

void musica(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

void setup()
{
  pinMode(bot, INPUT_PULLUP);
  pinMode(bot2, INPUT_PULLUP);
  pinMode(bot3, INPUT_PULLUP);
  pinMode(Pie, OUTPUT);
}

void loop()
{
  Botton = digitalRead(bot);
  Botton2 = digitalRead(bot2);
  Botton3 = digitalRead(bot3);
  
  if(Botton == LOW)
  {
    musica(Pie, tema1, 5);
    delay(1000);
  }
  
  if(Botton2 == LOW)
  {
    musica(Pie, tema2, 5);
    delay(1000);
  }
  
  if(Botton3 == LOW)
  {
    musica(Pie, tema3, 5);
    delay(1000);
  }
}